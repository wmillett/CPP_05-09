#include "BitcoinExchange.hpp"






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
        throw std::runtime_error("No header in file");
    }
    while(std::getline(_input, line)){

            while(isspace(line[i]))
                i++;
            while(isnumber(line[i])){
                year.push_back(line[i]);
                i++;
            }
            check = atol(year.c_str());
            if(check < 2009 || check > 2022){
                throw std::runtime_error("Year range is invalid");
            }
            if(line[i] != '-')
                throw std::runtime_error("Invalid date format");
            i++;
            while(isnumber(line[i])){
                month.push_back(line[i]);
                i++;
            }
            check = atol(month.c_str());
            if(check < 1 || check > 12){
                throw std::runtime_error("Month range is invalid");
            }
            if(line[i] != '-')
                throw std::runtime_error("Invalid date format");
            i++;
            while(isnumber(line[i])){
                day.push_back(line[i]);
                i++;
            }
            check = atol(day.c_str());
            if(check < 1 || check > 31){
                throw std::runtime_error("Day range is invalid");
            }
            if(line[i++] != ' ')
                throw std::runtime_error("Invalid input format");
            if(line[i++] != '|')
                throw std::runtime_error("Invalid input format");
            if(line[i++] != ' ')
                throw std::runtime_error("Invalid input format");
            while(isnumber(line[i]) || line[i] == '.'){
                if(line[i] == '.' && dot)
                    throw std::runtime_error("Invalid input format");
                bitcoin.push_back(line[i++]);
                if(line[i] == '.')
                    dot = 1;
            }
            value = std::stof(bitcoin);
            // check = atol(bitcoin.c_str());
            if(value <= 0 || value > INT_MAX){
                throw std::runtime_error("Bitcoin value invalid");
            }
            while(isspace(line[i]))
                i++;
            if(line[i])
                 throw std::runtime_error("Invalid input format");
            
            date = year + "-" + month + "-" + day;

            std::map<std::string, float>::iterator it = _map.find(date);
             if (it != _map.end()) {
                std::cout << date << " => " << value << " = " << it->second * value << std::endl;
            } 
            else {
                //find the lowest bound one here;
            }








            year.clear();
            month.clear();
            day.clear();
            bitcoin.clear();
            first.clear();
            second.clear();

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
Bitcoin::Bitcoin(const std::string input): _data(DATA), _input(input), _fileName(input){
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
            date = input.substr(0, commaPos);
            value = std::stof(input.substr(commaPos + 1));
            _map[date] = value;
        } 
        else { 
            throw std::runtime_error("Invalid data format");
        }
    }

}
Bitcoin::Bitcoin(const Bitcoin& other){
    openFiles(other.getFileName());
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