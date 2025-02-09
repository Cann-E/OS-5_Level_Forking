#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    std::cout << "I am the parent process" << std::endl;
    
    for(int i=0; i<2; i++){
        if(fork()==0){
            std::cout << "I am the child process " << i << std::endl;

            if(i==1){
                for(int j=0; j<2; j++){
                    if(fork()==0){
                        std::cout << "I am a grandchild process from child process " << i << std::endl;
                        
                        if(j==1){
                            for(int z=0; z<2; z++){
                                if(fork()==0){
                                    std::cout << "I am a great-grandchild process from child process " << j << std::endl;
                                    
                                    if(z==0){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }
                                    
                                    if(z==1){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }
                                }
                                wait(nullptr);
                                _exit(0);
                            }
                        }
                        
                        if(j==0){
                            for(int z=0; z<2; z++){
                                if(fork()==0){
                                    std::cout << "I am a great-grandchild process from child process " << j << std::endl;
                                    
                                    if(z==1){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }
                                    
                                    if(z==0){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }
                                }
                                wait(nullptr);
                            }
                        }
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }

            if(i==0){
                for(int j=0; j<2; j++){
                    if(fork()==0){
                        std::cout << "I am a grandchild process from child process " << i << std::endl;

                        if(j==1){
                            for(int z=0; z<2; z++){
                                if(fork()==0){
                                    std::cout << "I am a great-grandchild process from child process " << j << std::endl;

                                    if(z==0){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }

                                    if(z==1){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }
                                }
                                wait(nullptr);
                            }
                        }

                        if(j==0){
                            for(int z=0; z<2; z++){
                                if(fork()==0){
                                    std::cout << "I am a great-grandchild process from child process " << j << std::endl;

                                    if(z==1){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }

                                    if(z==0){
                                        for(int x=0; x<2; x++){
                                            if(fork()==0){
                                                std::cout << "I am a great-great-grandchild process from child process " << x << std::endl;
                                                _exit(0);
                                            }
                                            wait(nullptr);
                                        }
                                    }
                                }
                                wait(nullptr);
                            }
                        }
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }
            wait(nullptr);
            _exit(0);
        }
        wait(nullptr);
    }

    return 0;
}



Parent (Level 0)
 ├── Child (Level 1)
 │   ├── Grandchild (Level 2)
 │   │   ├── Great-Grandchild (Level 3)
 │   │   │   ├── Great-Great-Grandchild (Level 4)
 │   │   │   ├── Great-Great-Grandchild (Level 4)
 │   │   ├── Great-Grandchild (Level 3)
 │   │       ├── Great-Great-Grandchild (Level 4)
 │   │       ├── Great-Great-Grandchild (Level 4)
 │   ├── Grandchild (Level 2)
 │       ├── Great-Grandchild (Level 3)
 │       │   ├── Great-Great-Grandchild (Level 4)
 │       │   ├── Great-Great-Grandchild (Level 4)
 │       ├── Great-Grandchild (Level 3)
 │           ├── Great-Great-Grandchild (Level 4)
 │           ├── Great-Great-Grandchild (Level 4)
 ├── Child (Level 1)
     ├── Grandchild (Level 2)
     │   ├── Great-Grandchild (Level 3)
     │   │   ├── Great-Great-Grandchild (Level 4)
     │   │   ├── Great-Great-Grandchild (Level 4)
     │   ├── Great-Grandchild (Level 3)
     │       ├── Great-Great-Grandchild (Level 4)
     │       ├── Great-Great-Grandchild (Level 4)
     ├── Grandchild (Level 2)
         ├── Great-Grandchild (Level 3)
         │   ├── Great-Great-Grandchild (Level 4)
         │   ├── Great-Great-Grandchild (Level 4)
         ├── Great-Grandchild (Level 3)
             ├── Great-Great-Grandchild (Level 4)
             ├── Great-Great-Grandchild (Level 4)
