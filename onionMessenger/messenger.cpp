
#include "common.h"
#include "messenger.h"
#include "keymanager.h"

using namespace newkey;
using namespace socksv;

namespace newmsger{

    Messenger::Messenger(string githubID, string passPhrase)
    {
        this->km = new Keymanager(githubID, passPhrase);
        if(km->Validation() == 1)
            CheckPW();
            exit(1);
    }

    Messenger::~Messenger(){}

    void Messenger::Loop(){
        // create 3 threads
        // 1. recv new node info / node exit notification
        // 2. recv messages
        // 3. handle user input / print output to screen
        // 3rd thread will be handled in anohter module

        Sockserver *socksv = new Sockserver();
        std::thread socketThread = socksv->MessageServer();

        // for now, no additional executions are left so we should
        // wait for the thread to return
        socketThread.join();
    }

}
