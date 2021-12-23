//
//

#include"FileEncrypter.h"
#include<iostream>
using namespace std;

int main() {
	string filepath;
	char yn=' ';

	bool complete = false;
	//Will set to false the program runs its operation without an error

	while (!complete) {
		cout << "Enter the file which you would like to encrypt\n";
		getline(cin, filepath);
		FileEncrypter encryptor(filepath);
		encryptor.setBit_pairs(5, 6);
		encryptor.setBit_pairs(0, 4);
		encryptor.setBit_pairs(1, 3);
		try {
			encryptor.encryptFile();

			cout << "The specified file has been encrypted, check " 
				<< encryptor.generateOutput_filepath() << " to see results\n";
			while (yn != 'Y' && yn != 'N') {
				cout << "Would you like a decrypted version of the encrypted copy for varification?[y/n]\n";
				cin.get(yn);
				yn = toupper(yn);
			}
			if (yn == 'Y') {
				encryptor.setFilepath(encryptor.generateOutput_filepath());
				encryptor.encryptFile();
				cout << "The specified file has been encrypted, check " << encryptor.generateOutput_filepath() << " to see results\n";
			}
			complete = true;
		}
		catch (const FileEncrypter::FilepathNotSetException &e) {
			cout << "Filepath cannot be null, please restart driver and enter a value for filepath\n";
		}
	}
	cout << "Press any key to exit\n";
	cin.get();
	return 0;
}