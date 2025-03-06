#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 函数将字符串转换为小写
string toLowerCase(const string& str) {
    string lowerStr = str;
    for(auto &c : lowerStr){
        c = tolower(c);
    }
    return lowerStr;
}

int main(){
    string word, sentence;
    
    // 读取输入
    cin >> word;
    cin >> sentence;
    
    // 生成小写版本用于匹配
    string lowerWord = toLowerCase(word);
    string lowerSentence = toLowerCase(sentence);
    int wordLen = word.length();
    int sentenceLen = sentence.length();
    
    string result = "";
    int i = 0;
    
    while(i < sentenceLen){
        // 检查当前位置是否匹配目标单词
        if(i + wordLen <= sentenceLen && lowerSentence.substr(i, wordLen) == lowerWord){
            // 判断是否需要在前面添加空格
            if(result.length() > 0 && result.back() != ' '){
                result += " ";
            }

            // 添加原始单词
            result += sentence.substr(i, wordLen);
            i += wordLen;

            // 判断是否需要在后面添加空格
            // 如果不是句子结尾，并且下一个部分不是另一个目标单词，添加空格
            if(i < sentenceLen){
                if(!(i + wordLen <= sentenceLen && lowerSentence.substr(i, wordLen) == lowerWord)){
                    result += " ";
                }
            }
            continue;
        }
        else{
            // 当前字符不是目标单词的一部分，累积非目标单词的字符
            string temp = "";
            while(i < sentenceLen){
                // 检查当前位置是否匹配目标单词
                if(i + wordLen <= sentenceLen && lowerSentence.substr(i, wordLen) == lowerWord){
                    break; // 目标单词开始的位置，退出累积
                }
                // 累积当前字符
                temp += sentence[i];
                i++;
            }
            if(!temp.empty()){
                if(result.length() > 0 && result.back() != ' '){
                    result += " ";
                }
                result += temp;
            }
        }
    }
    
    // 去掉开头和结尾的空格
    size_t start = result.find_first_not_of(' ');
    size_t end = result.find_last_not_of(' ');
    if(start != string::npos && end != string::npos){
        result = result.substr(start, end - start + 1);
    }
    
    cout << result;
    
    return 0;
}

