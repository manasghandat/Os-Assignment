# Readers Writers Problem

In computer science, the Readers-Writers Problem is a well-known synchronisation issue. It happens when several processes (or threads) are seeking for use of a shared resource, such a file, database, or chunk of RAM. In the Readers-Writers problem there are some processes ( termed readers ) who only read the shared data, and never change it, and there are other processes ( termed writers ) who may change the data in addition to or instead of reading it. There is no limit to how many readers can access the data simultaneously, but when a writer accesses the data, it needs exclusive access.

The Readers-Writers Problem is broadly classified into three types:
* First readers-writers problem : In this problem when a reader wants to access a data and there is no writer accessing data then the reader will read the data. This leads to starvation as the reader can jump ahead of a queue of writers so a continuous stream of readers leads to starvation. Note that 2 readers can read data at the same time as long as they are not reading the same data.
* Second readers-writers problem : In this problem when writer wants to access a data and there is no reader accessing data then the writer will write the data. This leads to starvation of readers.
* Third / Starve-free readers-writers problem : In both of the above mentioned problems there can occur starvation. As a result, a starve free approach to the readers-writers called the starve-free readers writers problem

## Starve Free Readers-Writers problem

One possible solution to the "Starve-free Readers-Writers Problem" is to use a counting semaphore and two mutexes. The counting semaphore is used to keep track of the number of readers currently accessing the resource. The two mutexes are used to ensure that only one writer can access the resource at a time and to protect the shared counter.

The algorithm can be as follows:

#### Readers Algorithm

* Wait on the counting semaphore.
* Acquire the shared counter mutex.
* Increment the shared counter.
* If the shared counter is 1, acquire the writer mutex.
* Release the shared counter mutex.
* Signal the counting semaphore.
* Access the shared resource.
* Acquire the shared counter mutex.
* Decrement the shared counter.
* If the shared counter is 0, release the writer mutex.
* Release the shared counter mutex.

#### Writers Algorithm

* Acquire the writer mutex.
* Access the shared resource.
* Release the writer mutex.

