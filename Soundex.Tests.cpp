#include <string>
#include<cctype>
#include<unordered_map>
#include<algorithm>

char maptoSoundexcode(char c) {
static const std::unordered_map<char, char> soundexMap = {

{'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
{'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
{'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
{'D', '3'}, {'T', '3'}, {'L', '4'}, {'M', '5'},
{'N', '5'}, {'R', '6'}
};

c = toupper(c);
auto it =soundexMap.find(c);
return (it != soundexMap.end())? it ->second :'0';
}

void appendSoundex(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}

std::string paddingSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    if (paddedSoundex.length() > 4) {
        paddedSoundex.resize(4);
    } else {
        paddedSoundex.resize(4, '0');
    }

    return paddedSoundex;
}
std::string buildSoundex(const std::string& name, char firstletter, char prevCode, std::string soundex size_t i);
if(index >= name.length() || soundex.length() ==4) {
return paddingSoundex(soundex);
}

char code =mapToSoundexCode(name[index]);
appendSoundex(soundex, code, prevCode);

return buildSoundex(name, firstletter, prevCode, soundex, index + 1);
}

std::string generateSoundex(const std::string& name) {
if(name.empty()) return "";
return buildSoundex(name, toupper(name[0]), mapToSoundexcode(name[0]), std::string(1,toupper(name[0])), 1);
}
