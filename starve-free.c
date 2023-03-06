int readcount = 0;
semaphore resource;
semaphore rmutex;
semaphore serviceQueue;

reader(){
    //Entry Section
    wait(serviceQueue);
    wait(rmutex);
    readcount++;
    if(readcount==1){
        wait(resource);
    }
    signal(serviceQueue);
    signal(rmutex);

    //Critical Section

    //Exit Section 
    signal(rmutex);
    readcount--;
    if(readcount==0){
        signal(resource);
    }
    signal(serviceQueue);
}

writer(){
    //Entry Section
    wait(serviceQueue);
    wait(resource);
    signal(serviceQueue);

    //Critical Section

    //Exit Section
    signal(resource);
}