#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <windows.h>
#include <shobjidl.h>

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"Comdlg32.lib")



#include "json.hpp"
// #include <wstring.h>
#include <filesystem>
#include <processthreadsapi.h>
using namespace std;


namespace SetColor
{
    string RESET =       "\033[0m"           ;
    string BLACK =       "\033[30m"          ;   /* Black */
    string RED =         "\033[31m"          ;   /* Red */
    string GREEN =       "\033[32m"          ;   /* Green */
    string YELLOW =      "\033[33m"          ;   /* Yellow */
    string BLUE =        "\033[34m"          ;   /* Blue */
    string MAGENTA =     "\033[35m"          ;   /* Magenta */
    string CYAN =        "\033[36m"          ;   /* Cyan */
    string WHITE =       "\033[37m"          ;   /* White */
    string BOLDBLACK =   "\033[1m\033[30m"   ;   /* Bold Black */
    string BOLDRED =     "\033[1m\033[31m"   ;   /* Bold Red */
    string BOLDGREEN =   "\033[1m\033[32m"   ;   /* Bold Green */
    string BOLDYELLOW =  "\033[1m\033[33m"   ;   /* Bold Yellow */
    string BOLDBLUE =    "\033[1m\033[34m"   ;   /* Bold Blue */
    string BOLDMAGENTA = "\033[1m\033[35m"   ;   /* Bold Magenta */
    string BOLDCYAN =    "\033[1m\033[36m"   ;   /* Bold Cyan */
    string BOLDWHITE =   "\033[1m\033[37m"   ;   /* Bold White */
}; // namespace SetColor

namespace ASCIIArt
{
    string LargeBlenderLogo = R"V0G0N(

                                  ,g██▄╕
                                  ████████┐
                                    █████████,
                                      "████████▄,
                                         ▀████████▄,
               ,▄████████████████████████████████████╦
               █████████████████████████████████████████╗
                 """"""""""""████████████▀╙"""╙▀███████████,        ████,                ,,,,,                                                       ⌐████
                          ╓██████████`             `▀████████,      █████                █████                                                       █████                                   `█▌\
                       ,▄█████████▀     ,███████▄     ╚███████W     █████  ,▄███▄,,      █████     ,▄███████▄,            ,▄█████╖         ,⌐▄███▄,  █████     ,▄███████▄,            ╓███L  '═╛
                    ,▄███████████     ▄████████████,    ███████L    █████████████████,   █████  ,███████████████   █████████████████    ╓█████████████████  ,███████████████   ███████████L
                 ,g█████████████▌    ███████████████    ╘███████    ███████`   `███████  █████ ▐█████       █████  ███████     ██████  ███████    ╙███████ ,█████       █████  ███████▀
              ,g████████████████     ████████████████    ███████▄   █████         █████L █████ ███████████████████ █████        █████ ██████        ▐█████ ███████████████████ ██████
            ╓██████████" ███████L    ▀██████████████    ╒███████▌   █████         █████▌ █████ ███████████████████ █████        █████ ██████         █████ ███████████████████ █████
         ╓██████████▀    ████████      ████████████    ,████████    ██████       ██████  █████ ██████       █,     █████        █████  █████▄      ,██████ ▀█████       █,     █████
       ╓██████████`      █████████W       ▀████╙      g█████████    ██████████████████   █████  ▀███████████████   █████        █████   ██████████████████  '███████████████   █████
       ████████"          ██████████▄,             ,▄██████████     █████ █████████▀     █████     ███████████     █████        █████     ▀█████████ █████     ███████████     █████
        ▀███╜              ▀████████████▄g╕⌐⌐⌐╓g▄████████████▀
                             ███████████████████████████████
                               ╙█████████████████████████╜
                                  '▀█████████████████▀"
                                        `""╙╙╙""`

 )V0G0N";

    string BlenderLogo = R"V0G0N( 

|| Welcome to the Blender version selector! ||
  
                        @@@@                   
                       &@@@@@@/               
                          @@@@@@@@            
         (@@@@@@@@@@@@@@@@@@@@@@@@@@@         
        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
                  @@@@@@@@*        @@@@@@@@   
               @@@@@@@@     @@@@@#    @@@@@@@ 
           (@@@@@@@@@@   (@@@@@@@@@@    @@@@@@
        @@@@@@@@@@@@@    @@@@@@@@@@@@   @@@@@@
     @@@@@@@@% @@@@@@(   ,@@@@@@@@@@    @@@@@@
  @@@@@@@@%    .@@@@@@@     /@@@@,     @@@@@@@
 /@@@@@(        .@@@@@@@@(          @@@@@@@@@ 
                  @@@@@@@@@@@@@@@@@@@@@@@@@   
                     @@@@@@@@@@@@@@@@@@@(     
                          @@@@@@@@@*          

                                            )V0G0N";

    string Info =  R"V0G0N( 
  ___        __       
 |_ _|_ __  / _| ___  
  | || '_ \| |_ / _ \ 
  | || | | |  _| (_) |
 |___|_| |_|_|  \___/ 
                       )V0G0N";

}

// int main()
// {
//     // Create and open a text file
//     ofstream MyFile("filename.txt");

//     // Write to the file
//     MyFile << "Files can be tricky, but it is fun enough!";

//     // Close the file
//     MyFile.close();


//     // Create a text string, which is used to output the text file
//     string myText;

//     // Read from the text file
//     ifstream MyReadFile("filename.txt");

//     // Use a while loop together with the getline() function to read the file line by line
//     while (getline(MyReadFile, myText))
//     {
//         // Output the text from the file
//         cout << myText;
//     }

//     // Close the file
//     MyReadFile.close();
// }
using namespace nlohmann;

// json settings = {
// {"blenderInstallations",{
//  {{"293", {{"directory", "C:/Program Files/Blender Foundation/BlenderLTS 2.93/blender-2.93.0-5368859a669d-windows64"}}}},
//   {{"300",
//     {{"directory",
//       "C:/Program Files/Blender Foundation/blender-3.0.0-alpha+master.94c4a9995e43-windows.amd64-release/blender-3.0.0-alpha+master.94c4a9995e43-windows.amd64-release"}}}}}}};
ifstream settingsFile;
json jsonSettings;
string versionSelectorExecutableFilePathIncludingExecutableFileName;
string versionSelectorExecutableFilePathExcludingExecutableFileName;
string settingsJsonFilePathIncludingFileName;

int open(string pathToBlenderDirExcludingExecutableFileName, string pathToBlendFileIncludingFileNameAndExtension);

int prepare()
{
    cout << ASCIIArt::BlenderLogo;
    // Prepare variable:
    versionSelectorExecutableFilePathExcludingExecutableFileName;
    {
        // @information The commented code was replaced by the shorter code within this block to improve readability & make maintenance easier.
        
        int indexOfLastSlash;
        for (int i; i < versionSelectorExecutableFilePathIncludingExecutableFileName.length(); i++)
        {
            char c = versionSelectorExecutableFilePathIncludingExecutableFileName[i];
            if (c == '\\' || c == '/')
            {
                indexOfLastSlash = i;
            }
        }
        versionSelectorExecutableFilePathExcludingExecutableFileName = versionSelectorExecutableFilePathIncludingExecutableFileName;
        versionSelectorExecutableFilePathExcludingExecutableFileName.erase(indexOfLastSlash + 1, string::npos);

        // versionSelectorExecutableFilePathExcludingExecutableFileName.erase(
        // max(versionSelectorExecutableFilePathIncludingExecutableFileName.find_last_of('/'), versionSelectorExecutableFilePathIncludingExecutableFileName.find_last_of('\\')) + 1,
        // string::npos);
        // cout << "\n\nWaao " << versionSelectorExecutableFilePathIncludingExecutableFileName << "\nwaao\n";
    }

    // Prepare variable:
    settingsJsonFilePathIncludingFileName;
    {
        settingsJsonFilePathIncludingFileName = versionSelectorExecutableFilePathExcludingExecutableFileName + "settings.json";
    }





    settingsFile.open(settingsJsonFilePathIncludingFileName);
    if (settingsFile.is_open())
    {
        settingsFile >> jsonSettings;
    } else
    {
        cout << "\nCannot open the settings.json file! \nClose all text editors and any potential other instances of this software and try again\n";
        return 1;
    }
    return 0;
}

int startedWithoutFile()
{

    cout << "\nHi\n";

    // cout << jsonSettings.dump();
    
    // ofstream myfile;
    // myfile.open("settings.json");
// 
    // myfile << jsonSettings.dump();
    return 0;
}

int startedWithFile(string filePath)
{
    // std::string WhatEverHoldsThePath = argv[1];
    // WhatEverHoldsThePath = "BLENDER-v293RENDH"; // Used during development for easier debugging, this is a part of the first line of any blend file
    // ifstream file(filePath);
    // string data;
    // file >> data[1];
    ifstream blendFile;

    blendFile.open(filePath);
    char textFromBlendFile[] = ".................";
    blendFile >> textFromBlendFile; // All the dots will now have been replaced by the first characters in the file documment provided by our text based path

    startBlenderVersionBasedOn_textFromBlendFile:
    string textFromBlendFileStringVersion = textFromBlendFile;
    string BlendLastOpenedVersion;
    for (int i = 0; i < textFromBlendFileStringVersion.length()+1; i++)
    {
        char c = textFromBlendFileStringVersion[i-1];
        string allowedCharacters = "1234567890";
        for (char allowedC : allowedCharacters)
        {
            if (allowedC == c)
            {
                // test.push_back(c);
            }
        }
        if (allowedCharacters.find(c) != string::npos)
        {
            BlendLastOpenedVersion.push_back(c);
        }
    }


    map<string, string> mapToPrint =
    {
        {"File content", textFromBlendFile},
        {"File path", filePath},
        {"Blend Last Opened Version", BlendLastOpenedVersion},
        {"Executable path to version selector", versionSelectorExecutableFilePathIncludingExecutableFileName},
        {"Executable path to version selector excluding filename", versionSelectorExecutableFilePathExcludingExecutableFileName},
        {"Settings path", settingsJsonFilePathIncludingFileName},
    };

    for (std::pair<const string, const string> pairToPrint : mapToPrint)
    {
        std::cout << "\n" << pairToPrint.first << ":\n    " << pairToPrint.second << std::endl;
    }




    // cout << endl << jsonSettings.<< endl;

    for (json j : jsonSettings)
    {
        if(j.contains(BlendLastOpenedVersion))
        {
            cout << endl << "!!" << j.find(BlendLastOpenedVersion).value().find("executablePath").value();
            open(string(j.find(BlendLastOpenedVersion).value().find("executablePath").value()), filePath);
            return 0; // @information EARLY RETURN!
        } else
        {
            // for (auto a : j.find("blenderInstallations").value().items())
            // {
                // cout << a.key().c_str()<<endl;
            // }
        }
    }
    cout << ASCIIArt::Info;
    cout << "\nCant find a matching Blender version!";
    cout << "\n";
    cout << "\nThis file was last opened in Blender v" + BlendLastOpenedVersion;
    cout << "\nof which couldnt be matched against your settings.json file";
    cout << "\n";
    cout << "\nIf you would still like to open the file, please enter the version number";
    cout << "of the Blender installation that you would like to open the file with";
    cout << ", otherwise you can close this window.";
    cout << "\n";

    // cout  <<  jsonSettings.find("blenderInstallations").value().items().begin().key()  <<  endl;


    for (nlohmann::detail::iteration_proxy_value<nlohmann::detail::iter_impl<nlohmann::basic_json<>>> basicJsonPairOfVersionKeyAndItsValues :
         jsonSettings.find("blenderInstallations").value().items())
    {
        cout << "\n\n* Blender v" << basicJsonPairOfVersionKeyAndItsValues.key();
        for (auto basicJsonPairsInsideEachVersion : basicJsonPairOfVersionKeyAndItsValues.value().items())
        {
            cout << "\n    " << basicJsonPairsInsideEachVersion.key() << ": " << basicJsonPairsInsideEachVersion.value();
        }
    }
    // std::cout << "\nFile content:\n    " << textFromBlendFile << "\nFile:\n    " << filePath << endl << endl; // Prints contents of file
strcpy_s(textFromBlendFile, ".................");
    // textFromBlendFile = ".................";
    cin >> textFromBlendFile;
    goto startBlenderVersionBasedOn_textFromBlendFile;
    return 0;
}

int open(string pathToBlenderDirExcludingExecutableFileName, string pathToBlendFileIncludingFileNameAndExtension)
{
    if (pathToBlenderDirExcludingExecutableFileName.back() != '/')
    {
        pathToBlenderDirExcludingExecutableFileName.push_back('/');
    }
    // string systemCmdToExecute = "powershell -Command ''& \"" + pathToBlenderDirIncludingExecutableFileName + "blender.exe" + "\" \"" + pathToBlendFileIncludingFileNameAndExtension + "\" ''";
    string systemCmdToExecute = "\"\"" + pathToBlenderDirExcludingExecutableFileName + "blender.exe" + "\" \"" + pathToBlendFileIncludingFileNameAndExtension + "\"\"";
    
    cout << "\nSystemCmdToExecute:\n    " << systemCmdToExecute.c_str()<<endl;
    printf("\033[0m");
    system(systemCmdToExecute.c_str());
    return 0;
}

// string openfilename(string filter = "All Files (*.*)\0*.*\0", HWND owner = NULL) {
//   OPENFILENAME ofn;
//   char fileName[MAX_PATH] = "";
//   ZeroMemory(&ofn, sizeof(ofn));
// 
//   ofn.lStructSize = sizeof(OPENFILENAME);
//   ofn.hwndOwner = owner;
//   ofn.lpstrFilter = filter.c_str();
//   ofn.lpstrFile = fileName;
//   ofn.nMaxFile = MAX_PATH;
//   ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
//   ofn.lpstrDefExt = "";
// 
//   string fileNameStr;
// 
//   if ( GetOpenFileName(&ofn) )
    // fileNameStr = fileName;
// 
//   return fileNameStr;
// }

int main(int argc, char *argv[])
{
    // HWND owner;
    // cout << openfilename("All Files (*.*)\0*.*\0", owner).c_str();
    // system("pause");
    // system("pause");
    // return 0;


    printf("\033[0;35m");
    printf("\n");
    printf("||====================================||\n");
    printf("||Welcome to Blender version selector!||\n");
    printf("||====================================||\n");
    printf("\n");
    //   printf(ASCIIArt::BlenderLogo);
    //   return 0;
    // open("C:/Program Files/Blender Foundation/BlenderLTS 2.93/blender-2.93.0-5368859a669d-windows64", "C:/Users/Oliver/Desktop/Art and development/personal softwares/Blender version selector/testSubject.blend");
    // return 0;


    // system("pause");

    string openedBlendFilePath;
    versionSelectorExecutableFilePathIncludingExecutableFileName = argv[0];
    cout << versionSelectorExecutableFilePathIncludingExecutableFileName;
    // system("pause");c
    prepare();
    bool AlwaysPretendLikeWeOpenedABlendFile = 1;


    // system("pause");

    if (argv[1] == 0)
    {
        if (AlwaysPretendLikeWeOpenedABlendFile)
        {
            openedBlendFilePath = "C:/Users/Oliver/Desktop/Art and development/personal softwares/Blender version selector/testSubject.blend";
            goto startedWithFile;
        }
        //code code code
        //Maybe Prompt the user for a path and file name?
        //code code code
        //
        std::cout << "\nStarted without file\n";
        startedWithoutFile();
    } else
    {
        openedBlendFilePath = argv[1];
        cout << endl << openedBlendFilePath << endl;
        startedWithFile:



        std::cout << "\nStarted with file\n";
        startedWithFile(openedBlendFilePath);
    }
   system("pause");
//code code code
return 0;
}