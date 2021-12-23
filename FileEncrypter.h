#ifndef FILEENCRYPTER_H
#define FILEENCRYPTER_H
#include "Filter.h"
#include<string>
#include<fstream>
using namespace std;

class FileEncrypter :
    public Filter
{
    //this class builds upon filter for use with file streams
    //stores the filepath and verifies the file exists
    //Sets filepath to a empty string is given no filepath
    //or an invalid one
    // Throws FilepathNotSetException should the filepath
    //  not be set before attempting to reference the variable
private:
    string input_filepath;
public:
    FileEncrypter() {
        this->input_filepath = "";
    }
    FileEncrypter(string filepath){
        setFilepath(filepath);
    }


    void setFilepath(string input_filepath);
    string getFilepath();

    string generateOutput_filepath();
    //generates a name for output file, if the filepath
    //has been set - throws FilepathNotSetException otherwise

    void encryptFile();
    //creates an encrypted file at the address returned from generateOutput_filepath
    //Throws FilepathNotSetException if filepath is ""


    class FilepathNotSetException :
        public exception {
    private:
        string message;
    public:
        FilepathNotSetException() {
            this->message = "Methods refrencing filepath cannot be called while filepath is not set";
        };
        const char* what() const override {
            return message.c_str();
        };
    };
};
#endif