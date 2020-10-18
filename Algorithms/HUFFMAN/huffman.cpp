#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
class HuffmanNode
{
public:
char character;
int frequency;
HuffmanNode *lChild;
HuffmanNode *rChild;

HuffmanNode()
{
lChild = NULL;
rChild = NULL;
}	
};
class PQNode {
public:
HuffmanNode *data;
PQNode *next;
PQNode()
{
data = new HuffmanNode();
next = NULL;
}
};
class PriorityQueue{
public:
PQNode *start;
PQNode *last;
PQNode *loc;
PQNode *predLoc;
PriorityQueue()
{
start = NULL;
last = NULL;
loc = NULL;
predLoc = NULL;
}
bool isEmpty()
{
return start == NULL;
}
void print()
{
if(!isEmpty())
{
loc = start;
while(loc != NULL)
{
cout<<loc->data->character<<" ";
loc = loc->next;
}
cout<<endl;
}
else
{
cout<<"Empty"<<endl;
}

}
void search(int preference)
{
if(!isEmpty())
{
loc = start;
predLoc = NULL;
while(loc != NULL && loc->data->frequency <= preference)
{
predLoc = loc;
loc = loc->next;
}
loc == NULL;
}
}
void EnQueue(PQNode *node)
{
if (isEmpty())
{
start = node;
last = node;
}
else
{
search(node->data->frequency);

if(predLoc == NULL)
{
node->next = start;
start = node;
}
else if(predLoc == last)
{
last->next = node;
last = node;
}
else
{
node->next = predLoc->next;
predLoc->next = node;
}
}
}
HuffmanNode* deQueue()
{
HuffmanNode *answer = start->data;
PQNode *temp = new PQNode();
temp = start;
start = start->next;
delete temp;
return answer;
}
};class HuffmanTree
{
public:
string treeCode;
vector<string> codeVector;
vector<char> characters;
int index;
int countCharacters;
HuffmanNode *root;
PriorityQueue *myQueue;
HuffmanTree()
{
index = 0;
countCharacters = 0;
root = new HuffmanNode();	
myQueue = new PriorityQueue();
}

void getStandardQueue(string str)
{

int count [256];
for(int i = 0; i < 256; i++) //A = 62
{
count[i] = 0;
}

for(int i = 0; i < str.length(); i++)
{
count[(int)(str.at(i))] = count[(int)(str.at(i))] + 1;
}


for(int i = 0; i < 256; i++)
{
if(count[i]>0)
{
countCharacters++;
PQNode *nn = new PQNode();
//cout<<(char)(i)<<" occurs "<<count[i]<<" times."<<endl;
nn->data->character = ((char)(i));
nn->data->frequency = count[i];
myQueue->EnQueue(nn);

}
}
//myQueue->print();
cout<<endl;
}
void convertToTree()
{
while(myQueue->start->next != NULL)
{
PQNode *nNode = new PQNode();
nNode->data->lChild = myQueue->deQueue();
nNode->data->rChild = myQueue->deQueue();
nNode->data->frequency = nNode->data->lChild->frequency + nNode->data->rChild->frequency;
myQueue->EnQueue(nNode);
}
root = myQueue->deQueue();
}
void getCodes(HuffmanNode *temp, string code)
{
if(temp != NULL)
{
if(temp->lChild != NULL)
{
treeCode += "1";
getCodes(temp->lChild, code + "0");
}
if(temp->rChild != NULL)
{
treeCode += "1";
getCodes(temp->rChild, code + "1");
}
if(temp->rChild == NULL && temp->lChild == NULL)
{
treeCode += "0";
codeVector.push_back(code);
characters.push_back(temp->character);
}
}
}
void printCodes()
{
for(int i = 0; i < countCharacters; i++)
{
cout<<characters[i]<<" has code: "<<codeVector[i]<<endl;
}
}
string encode(string str)
{
string coded;
for(int i = 0; i < str.length(); i++)
{
for(int j = 0; j<countCharacters; j++)
{
if(str.at(i) == characters[j])
{
coded += (codeVector[j]);
break;
}
}
}
return coded;
}
void writeEncodedFile(char* fileName, string str)
{
ofstream fout (fileName, ofstream::binary);
for (int i = 0; i < str.length(); i++)
{
if(str.at(i) == '0')
fout<<0;
else
fout<<1;
}
fout.close();
}
void writeCharacterSequenceFile(char* fileName)
{
ofstream fout(fileName);
char c;
while(!characters.empty())
{
c = characters.back();
characters.pop_back();
fout << c;	
}
fout.close();
}
void readTreeFile(char* fileName)
{
ifstream file(fileName, ifstream::binary);
char c;
treeCode = "";
index = 0;
while(file >> c)
{
treeCode += c;
}
file.close();
}
void readCharacterFile(char* fileName)
{
while(!characters.empty())
{
characters.pop_back();
}
ifstream fin(fileName);
string line;
getline(fin, line);
for(int i = 0; i < line.length(); i++)
{
characters.push_back(line.at(i));
}
}
string readCodedFile(char* fileName)
{
ifstream file(fileName, ifstream::binary);
char c;
string line;
while(file >> c)
{
line += c;
}
file.close();
return line;
}
void constructRoot()
{
HuffmanNode* newNode = new HuffmanNode();
root = newNode;
}
void constructTreeFromFile(char* fileName1, char* fileName2)
{
//constructRoot();
//cout<<"Root Constructed"<<endl;
while(!codeVector.empty())
{
codeVector.pop_back();
}
readTreeFile(fileName1);
readCharacterFile(fileName2);

root = constructRestOfTheTree(getNextBlueprint());
}
char getNextBlueprint()
{
if(index<treeCode.length())
{
return treeCode.at(index++);
}
}
char getNextCharacterBlueprint()
{
char c;
if(!characters.empty())
{
c = characters.back();
//cout<<c<<endl;
characters.pop_back();
}
return  c;
}
HuffmanNode* constructRestOfTheTree(char blueprint)
{	
HuffmanNode* newNode = new HuffmanNode();
if(blueprint == '0')
{	
newNode->character = getNextCharacterBlueprint();
getNextBlueprint();
}
else if (blueprint == '1')
{
//cout<<"Left Case: "<<endl;
newNode->lChild = constructRestOfTheTree(getNextBlueprint());
//cout<<"Right Case: "<<endl;
newNode->rChild = constructRestOfTheTree(getNextBlueprint());

}
return newNode;	
}

string decode(string str)
{
string decodedString;
HuffmanNode* temp = new HuffmanNode();
temp = root;
for(int i = 0; i < str.length(); i++)
{
if(str.at(i) == '0')
{
temp = temp->lChild;
}
else if(str.at(i) == '1')
{
temp = temp->rChild;
}
if(temp->rChild == NULL && temp->lChild == NULL)
{
decodedString= decodedString + temp->character;
temp = root;
}
}
return decodedString;
}
};


int main(int argc, char** argv) {
HuffmanTree *obj = new HuffmanTree();

string str, coded, decoded;
cout<<"Enter a string"<<endl;
getline(cin, str);

obj->getStandardQueue(str);
obj->convertToTree();
cout<<obj->root->frequency<<" characters."<<endl;
obj->getCodes(obj->root, "");
obj->printCodes();
coded = obj->encode(str);
decoded = obj->decode(coded);
cout<<"Coded Form: "<<coded<<endl;
cout<<"Decoded Form: "<<decoded<<endl;
cout<<obj->treeCode<<endl;

string file1 = "EncodedText.bin";
string file2 = "EncodedTree.bin";
string file3 = "EncodedCharacterSequence.txt";

char fileName1 [file1.length() + 1];
strcpy(fileName1, file1.c_str());

obj->writeEncodedFile(fileName1, coded);

char fileName2 [file2.length() + 1];
strcpy(fileName2, file2.c_str());

char fileName3 [file3.length() + 1];
strcpy(fileName3, file3.c_str());

obj->writeEncodedFile(fileName2, obj->treeCode);
obj->writeCharacterSequenceFile(fileName3);
obj->constructTreeFromFile(fileName2, fileName3);
cout<< obj->decode(obj->readCodedFile(fileName1)) <<endl;

return 0;
}

