import xml.etree.cElementTree as ET
import sys

def find_str(s, char):
    index = 0

    if char in s:
        c = char[0]
        for ch in s:
            if ch == c:
                if s[index:index+len(char)] == char:
                    return index

            index += 1

    return -1



input = sys.argv[1]
output = sys.argv[2]
lst =[];
i=0;
j=1;
f = open(input, "r")
for line in f:
    if(line.rstrip() != ""):
        print (line.rstrip())
        lst.append(line)
f.close()

root = ET.Element("root")
testsuite = ET.SubElement(root, "testsuite", name="Test",tests="2",failures="1",disabled="0",errors="0",  time="0.2")


while (i<len(lst)):

    if(find_str(lst[i],"Test")):
        i=i-1
        print (lst[i])
        classNameTest = lst[i]
        if (find_str(lst[i-1],"failed")!=-1):
            i=i-1
            fail=ET.SubElement(testsuite,"testcase",classname=output,name =classNameTest, status="run",time ="0");
            failedContent ="";
            while(i+j <len(lst) and find_str(lst[i+j],"Test")==-1):
                failedContent+=lst[i+j];
                j=j+1;
            j=1;
            failure=ET.SubElement(fail,"failure",typ=failedContent);
            failure.text=lst[i];
            failedContent ="";
        else:
            i=i-1
            ET.SubElement(testsuite,"testcase",classname=output, name=classNameTest, status="run",time ="0");
    i=i+1;


#ET.SubElement(testsuite, "testcase", name="blah",status="run",time="0",classname="Test")
#ET.SubElement(testsuite, "testcase", name="blubb",status="run",time="0.2",classname="Test")

tree = ET.ElementTree(root)
tree.write(output)
