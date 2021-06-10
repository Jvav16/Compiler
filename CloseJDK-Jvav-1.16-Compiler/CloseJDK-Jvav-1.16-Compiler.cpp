﻿//                                                                                                                     
//                                                                                                               /   \
//                                                                                                               | R |
//          JJJJJJJJJJJ                                                            1111111           66666666    \   /
//          J:::::::::J                                                           1::::::1          6::::::6          
//          J:::::::::J                                                          1:::::::1         6::::::6           
//          JJ:::::::JJ                                                          111:::::1        6::::::6            
//            J:::::Jvvvvvvv           vvvvvvvaaaaaaaaaaaaavvvvvvv           vvvvvvv1::::1       6::::::6             
//            J:::::J v:::::v         v:::::v a::::::::::::av:::::v         v:::::v 1::::1      6::::::6              
//            J:::::J  v:::::v       v:::::v  aaaaaaaaa:::::av:::::v       v:::::v  1::::1     6::::::6               
//            J:::::j   v:::::v     v:::::v            a::::a v:::::v     v:::::v   1::::l    6::::::::66666          
//            J:::::J    v:::::v   v:::::v      aaaaaaa:::::a  v:::::v   v:::::v    1::::l   6::::::::::::::66        
//JJJJJJJ     J:::::J     v:::::v v:::::v     aa::::::::::::a   v:::::v v:::::v     1::::l   6::::::66666:::::6       
//J:::::J     J:::::J      v:::::v:::::v     a::::aaaa::::::a    v:::::v:::::v      1::::l   6:::::6     6:::::6      
//J::::::J   J::::::J       v:::::::::v     a::::a    a:::::a     v:::::::::v       1::::l   6:::::6     6:::::6      
//J:::::::JJJ:::::::J        v:::::::v      a::::a    a:::::a      v:::::::v     111::::::1116::::::66666::::::6      
// JJ:::::::::::::JJ          v:::::v       a:::::aaaa::::::a       v:::::v      1::::::::::1 66:::::::::::::66       
//   JJ:::::::::JJ             v:::v         a::::::::::aa:::a       v:::v       1::::::::::1   66:::::::::66         
//     JJJJJJJJJ                vvv           aaaaaaaaaa  aaaa        vvv        111111111111     666666666           
//                                                                                                                    
//         2021 (c) ExL Studios                                                                                       
//                                                                                                                    
//                                                                                                                    


// CloseJDK-Jvav-1.16-Compiler.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// includes

#include "CloseJDK-Jvav-1.16-Compiler.h"

// refers

void welcome();
char* getFileName(int, char*[]);
bool earlyProcess(char*);

// main

int main(int argc, char *argv[])
{
    char* targetFile = NULL; // file to compile
    welcome(); // show welcome
    targetFile = getFileName(argc, argv); // set filename
    earlyProcess(targetFile);
    return 0;
}
