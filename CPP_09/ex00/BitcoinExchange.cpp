#include "BitcoinExchange.hpp"



//TODO: change throw to print, get rid of extra 00000 before dates, fix converted value


void Bitcoin::convert(){
    std::string line;
    std::string year;
    std::string month;
    std::string day;
    std::string bitcoin;

    std::string date;

    long check;
    float value;
    bool dot = 0;
    size_t i = 0;

    std::getline(_input, line);
    if(line != "date | value"){
        std::cout << "Error: Invalid input format" << std::endl;
    }
    while(std::getline(_input, line)){
        while(1){

            while(isspace(line[i]))
                i++;
            while(isnumber(line[i])){
                year.push_back(line[i]);
                i++;
            }
            check = atol(year.c_str());
            if(check < 2009 || check > 2022){
                std::cout << "Error: Year range is invalid" << std::endl;
                break;
            }
            if(line[i] != '-'){
                std::cout << "Error: Invalid date format" << std::endl;
                break;
            }
            i++;
            while(isnumber(line[i])){
                month.push_back(line[i]);
                i++;
            }
            check = atol(month.c_str());
            if(check < 1 || check > 12){
                std::cout << "Error: Month range is invalid" << std::endl;
                break;
            }
            if(line[i] != '-'){
                std::cout << "Error: Invalid date format" << std::endl;
                break;
            }
            i++;
            while(isnumber(line[i])){
                day.push_back(line[i]);
                i++;
            }
            check = atol(day.c_str());
            if(check < 1 || check > 31){
                std::cout << "Error: Day range is invalid" << std::endl;
                break;
            }
            if(line[i++] != ' '){
                std::cout << "Error: Invalid input format" << std::endl;
                break;
            }
            if(line[i++] != '|'){
                std::cout << "Error: Invalid input format" << std::endl;
                break;
            }
            if(line[i++] != ' '){
                std::cout << "Error: Invalid input format" << std::endl;
                break;
            }
            while(isnumber(line[i]) || line[i] == '.'){
                if(line[i] == '.' && dot){
                    std::cout << "Error: Invalid input format" << std::endl;
                    break;
                }
                bitcoin.push_back(line[i]);
                if(line[i] == '.')
                    dot = 1;
                i++;
            }
            //std::cout << bitcoin << std::endl;


            check = atol(bitcoin.c_str());
            if(check <= 0){
                std::cout << "Error: Bitcoin value is negative" << std::endl;
                break;
            }
            if(check > 1000){
                 std::cout << "Error: Bitcoin value larger than 1000" << std::endl;
                 break;
            }
      
            value = std::stof(bitcoin);
            while(isspace(line[i]))
                i++;
            if(line[i]){
                std::cout << "Error: Invalid input format" << std::endl;
                break;
            }
        
            date = year + "-" + month + "-" + day;
            if(date.size() != 10){
                std::cout << "Error: Invalid date format" << std::endl;
                break;
            }

            // std::map<std::string, float>::iterator it = _map.find(date);
            // if (it != _map.end()) {
            //     std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            // } 
            // else {
            //     it = _map.lower_bound(date);
            //     if(it != _map.begin())
            //         it--;
            //     std::cout << "it->second: " << it->second << std::endl;
            //     std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            // }
            // break;

            std::map<std::string, float>::iterator it = _map.find(date);
            if (it != _map.end()) {
                check = value * it->second;
                if(check > std::numeric_limits<float>::max()){
                    std::cout << "Error: number is too large" << std::endl;
                    break;
                }
                if(check < std::numeric_limits<float>::min()){
                    std::cout << "Error: number is too small" << std::endl;
                    break;
                }
                std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            } 
            else {
                it = _map.lower_bound(date);
                if (it != _map.begin()) {
                    it--;
                    std::cout << date << " => " << value << " = " << it->second * value << std::endl;
                }
                else {
                    std::cout << "Error: No lower bound found for " << date << std::endl;
                }
            }
            break;
        }
            year.clear();
            month.clear();
            day.clear();
            bitcoin.clear();
            date.clear();
            i = 0;
            dot = 0;
    }
}

void Bitcoin::openFiles(const std::string& inputName) {
        _data.open(DATA);
        _input.open(inputName.c_str());
    }

Bitcoin::Bitcoin(){

}
Bitcoin::Bitcoin(const std::string input):_fileName(input){

    _data.open(DATA);
    _input.open(input);
    if(!_data.is_open()){
       throw std::runtime_error("Unable to open file: " + std::string(DATA));
    }
    if(!_input.is_open()){
        throw std::runtime_error("Unable to open file: " + _fileName);
    }
    std::string line;
    std::string date;
    size_t commaPos;
    float value;


    std::getline(_data, line);
    while(std::getline(_data, line)){
        commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            date = line.substr(0, commaPos);
            value = std::stof(line.substr(commaPos + 1));
            // std::cout << "date: " << date << std::endl;
            // std::cout << "here: " << value << std::endl;
            _map[date] = value;
        } 
        else {
            throw std::runtime_error("Invalid data format");
        }
    }
}
Bitcoin::Bitcoin(const Bitcoin& other){
    openFiles(other.getFileName());
    *this = other;
}

Bitcoin& Bitcoin::operator=(const Bitcoin& other){
    if (this != &other) {
            _data.close();
            _input.close();

            openFiles(other.getFileName());
        }
        return *this;
}
Bitcoin::~Bitcoin(){
    _data.close();
    _input.close();
}

 const std::string Bitcoin::getFileName(void) const{
    return _fileName;
 }

// const std::ifstream Bitcoin::getData(void) const{
//     return _data;
// }

// const char* BitcoinExchange::customException::what() const throw() {
// 	return "Error: could not open file.";
// }



