#include "FileEncrypter.h"
#include<iostream>

void FileEncrypter::setFilepath(string input_filepath) {
	ifstream file;
	file.open(input_filepath);
	if (file) {
		this->input_filepath = input_filepath;
	}
	else {
		this->input_filepath = "";
	}
	file.close();
}

string FileEncrypter::getFilepath() {
	if (this->input_filepath == "") {
		throw FilepathNotSetException();
	}
	return this->input_filepath;
}

string FileEncrypter::generateOutput_filepath() {
	if (this->input_filepath == "") {
		throw FilepathNotSetException();
	}
	//Generate an output_filepath in regards to the original file
	string output_filepath;
	if (this->getFilepath().find("__Encrypted.txt") != -1) {
		//Files ending in __Encrypted.txt will be assumed to be already encrypted by the program
		//therefore processing these files with the same program will create the decrypted version
		output_filepath = input_filepath.substr(0, input_filepath.find("__Encrypted.txt")) + "__Decrypted.txt";
	}
	else if(this->getFilepath().find(".txt")!=-1){
		//If the file hasn't already been encrypted, the new file will be
		output_filepath = this->getFilepath().substr(0,
			this->getFilepath().find(".txt")) + "__Encrypted.txt";
	}
	else {
		output_filepath = this->getFilepath() + "__Encrypted.txt";
	}
	return output_filepath;
}

void FileEncrypter::encryptFile(){
	if (getFilepath() == "") {
		throw FilepathNotSetException();
	}

//Reads data in .txt file located at input_filepath
//and writes to new output file
ifstream inputFile;
ofstream outputFile;
char c;

inputFile.open(this->getFilepath());
outputFile.open(generateOutput_filepath());
if (inputFile && outputFile) {
	//Makesure both files open correctly
	while ((c = inputFile.get()) != EOF) {
		//pass individual characters to filter
		c = encrypt(c);
		//then write to the output file
		outputFile << c;
	}
}
else {
	//if 
	if (!inputFile) {
		cerr << "An error occurred accessing " << this->getFilepath() << "\n"
			<< "Make sure " << this->getFilepath() << " is in the same directory as Encrypt.cpp\n";
	}
	if (!outputFile) {
		cerr << "An error occurred creating " << generateOutput_filepath() << "\n";
	}
}
inputFile.close();
outputFile.close();
}