#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

# define DATA "data.csv"

class Bitcoin{
    public:
        Bitcoin(const std::string input);
        Bitcoin(const Bitcoin& other);
        Bitcoin& operator=(const Bitcoin& other);
        ~Bitcoin();

        void convert();

        const std::string getFileName(void) const;
        // const std::ifstream getData(void) const;
    private:
        
        std::ifstream _data;
        std::ifstream _input;
        std::string _fileName;
        std::map<std::string, float>_map;

        Bitcoin();
        void openFiles(const std::string& inputName);
};


#endif
