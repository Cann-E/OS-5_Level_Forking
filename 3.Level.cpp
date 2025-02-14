#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    std::cout<<"I am the parent process "<<std::endl;
    for(int i=0;i<4;i++){
        if(fork()==0){
            std::cout<<"I am the child process "<< i <<std::endl;
            if(i==3){
                for(int j=0;j<4;j++){
                    if(fork()==0){
                        std::cout<<"I am the child process "<< i <<std::endl;//child process
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }
            if(i==2){
                for(int j=0;j<3;j++){
                    if(fork()==0){
                        std::cout<<"I am the grandchild process "<< i <<std::endl;
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }
            if(i==1){
                for(int j=0;j<2;j++){
                    if(fork()==0){
                        std::cout<<"I am the grandchild process "<< i <<std::endl;
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }
            if(i==0){
                for(int j=0;j<1;j++){
                    if(fork()==0){
                        std::cout<<"I am the grandchild process "<< i <<std::endl;
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }
            _exit(0);
        }
        wait(nullptr);
    }


    return 0;
}



I am the parent process
I am child process 0
I am a grandchild process from child process 0
I am child process 1
I am a grandchild process from child process 1
I am a grandchild process from child process 1
I am child process 2
I am a grandchild process from child process 2
I am a grandchild process from child process 2
I am a grandchild process from child process 2
I am child process 3
I am a grandchild process from child process 3
I am a grandchild process from child process 3
I am a grandchild process from child process 3
I am a grandchild process from child process 3
