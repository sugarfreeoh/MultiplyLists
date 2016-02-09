#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    string data;
    string temp;
    string tempVals;
    vector<string> vData;
    vector<string>::const_iterator itData;

    map< int,vector<int> > listValues;
    int vals;
    unsigned int index = 0;

    ifstream dataFile(argv[1]);

    if(dataFile.is_open())
    {
        while(getline(dataFile,data))
        {
            //cout << "Read in the following line: " << data << endl;
            
            stringstream listStream(data);
            
            while(getline(listStream,temp,'|'))
            {
                istringstream listValuesStream(temp);

                vData.push_back(temp);
            }

            //make sure data in the vector is right
            /*cout << "Values in list are:" << endl;
            for(itData = vData.begin(); itData != vData.end(); ++itData)
            {
                cout << *itData << endl;
            }*/

            for(itData=vData.begin(); itData!=vData.end(); ++itData)
            {
                string tmp = *itData;

                int loc = tmp.find_first_not_of(' ');

                tmp = tmp.substr(loc,tmp.size()-loc);

                istringstream vDataStream(tmp);

                while(getline(vDataStream,temp,' '))
                {
                    istringstream tempStream(temp);

                    tempStream >> vals;

                    listValues[index].push_back(vals);

                    //cout << listValues[index].back() << endl;
                }
                index++;
                vals = 0;
                //cout << endl;
            }

            index = 0;

            while(index < listValues[0].size())
            {
                //cout << listValues[0][index] << " x " << listValues[1][index] << " = " << listValues[0][index]*listValues[1][index] << endl;
                if(index != listValues[0].size()-1)
                {
                    cout << listValues[0][index]*listValues[1][index] << " ";
                }
                else
                {
                    cout << listValues[0][index]*listValues[1][index] << endl;
                }
                
                ++index;
            }

            index=0;

            //clean up and get ready for the next line
            vData.clear();
            listValues.clear();

            //cout << endl;
        }
    }

    dataFile.close();

    return 0;
}
