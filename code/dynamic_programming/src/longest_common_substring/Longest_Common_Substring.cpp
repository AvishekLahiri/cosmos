// Space Complexity: O(n)
// Time Complexity: O(m*n) 

#include <string>
#include <iostream>
#include <vector> 

std::string LongestCommonSubstring(std::string str1, std::string str2) 
{ 
    std::string temp;
    // longest string is str1 and the smallest string is str2
    if( str2.size() > str1.size() ) {
        temp = str1;
        str1= str2;
        str2 = temp;
    }
    int m, n; 
    m = str1.size();
    n = str2.size();

    int maxlength = 0; //length of longest common Substring
    int end; //ending point of longest common Substring
    
    std::vector< std::vector<int> > consqRow(2,std::vector<int> (n+1,0)); //store result of 2 consecutive rows
    int curr = 0; //current row in the matrix  

    //maintaing the array for consequtive two rows
    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            if (str1[i - 1] == str2[j - 1]) { 
                consqRow[curr][j] = consqRow[1 - curr][j - 1] + 1; 
                if ( consqRow[curr][j] > maxlength ) { 
                    maxlength = consqRow[curr][j]; 
                    end = i - 1; 
                }
            } 
            else { 
                consqRow[curr][j] = 0; 
            } 
        } 
        curr = 1 - curr; // changing the row alternatively
    } 

    if (maxlength == 0) { 
        return "-1"; 
    } 
    else{
        std::string s = "";
        // string is from end-maxlength+1 to end as maxlength is the length of
        // the common substring.
        for(int i=end-maxlength+1; i<=end; i++){
            s+=str1[i];
        }
        return s; 
    }
}

int main(){

    std::string string1 = "cosmos"; 
    std::string string2 = "OpenGenusmos";
    std::string lcsStr = LongestCommonSubstring(string1, string2);
    std::cout << "String1: " << string1 << "\nString2: " << string2 << "\n";
    if(lcsStr == "-1"){
        std::cout << "No common substring\n"; 
    }
    else{
        std::cout << "Longest Common Substring: " << lcsStr << " (of length: " << lcsStr.size() << ")\n";
    }
    return 0;
}
