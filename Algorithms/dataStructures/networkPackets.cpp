#include <iostream>
#include <deque>
#include <vector>


// Network packet object
struct Request
{
    int arrival_time, process_time;
    
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time), process_time(process_time) {}
};

/*
If the network packet had been processed,
and if so, the time at which the packet had been processed
*/
struct Response
{
    bool dropped;
    int  start_time;
    
    Response(bool dropped, int start_time):
        dropped(dropped), start_time(start_time) {}
};

/*
Given a set buffer size, process network packet requests in order of occurrences
1) If the buffer is empty, process the network packet immediately
2) If the buffer is full and connot take another request, don't process the network packet
3) Enqueue the network packets into the buffer that needs to process
4) Deque the network packets FIFO fashion as they complete processing
*/
class Buffer
{
private:
    int size;
    int current_time = 0;
    std::deque <int> finish_time;
    
public:
    Buffer(int size):
        size(size) {}
    
    Response Process(const Request &request)
    {
        if (!finish_time.empty())
        {
            if (finish_time.front() == request.arrival_time)
            {
                while (finish_time.front() == request.arrival_time)
                {
                    finish_time.pop_front();
                }
            }
        }
        
        if (finish_time.empty())
        {
            current_time += request.process_time;
            finish_time.push_back(current_time);
            return Response(false, request.arrival_time);
        }
        
        if (finish_time.size() >= size)
        {
            return Response(true, -1);
        }
        
        else
        {
            Response response = Response(false, current_time);
            current_time += request.process_time;
            finish_time.push_back(current_time);
            return response;
        }
    }
};


// Forward declarations
std::vector <Request> ReadRequests();
std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer);
void PrintResponses(const std::vector <Response> &responses) ;


/*
Input
1) First line of input consists of 2 integers:
    1 is size of buffer
    2 is number of packet requests
2) The next n lines (n being number of packet requests) consist of 2 integers:
    1 is the time the network packet had arrived in the queue
    2 is the time the packet will take to process
 
 Output
 A) List of integers representing the time each packet sent to queue began its processing
 B) -1 designates that the packet had been dropped due to a full buffer
*/
int main()
{
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();
    
    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);
    
    PrintResponses(responses);

    return 0;
}


// Get the N network packets' arrival time and processing time
std::vector <Request> ReadRequests()
{
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    
    for (int i = 0; i < count; ++i)
    {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }

    return requests;
}


/*
Calculate the time that each packet in the queue will begin processing
or if the packet had been dropped due to a full buffer
*/
std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer)
{
    std::vector <Response> responses;
    
    for (int i = 0; i < requests.size(); ++i)
    {
        responses.push_back(buffer->Process(requests[i]));
    }
    
    return responses;
}


/*
Print
A) The time that processing started for each packet
B) -1 if the packet had not been able to fit in the buffer at time of processing
*/
void PrintResponses(const std::vector <Response> &responses)
{
    for (int i = 0; i < responses.size(); ++i)
    {
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
    }
}
