#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    std::cout << "I am the parent process" << std::endl;
    for (int i=0;i<3;i++){
        if(fork()==0){
            std::cout << "I am the child process " << i << std::endl;
            if(i==1){
                for(int j=0;j<1;j++){
                    if(fork()==0){
                        std::cout << "I am a grandchild process from child process " << i << std::endl;
                        _exit(0);
                    }
                    wait(nullptr);
                }
            }
            _exit(0);

        }
        wait(nullptr);
    }
 
  // 
  // 
  // 
    return 0;






    
}