# Synchronous Data Transmission
### Introduction
Synchronous data transmission is real-time communication that requires the transmitter and receiver to be present in the same time and/or space. It has low latency due to real-time communication.

### Examples of synchronous data transmission
- Chatrooms
- Video conferencing
- Telephonic conversations
- Face-to-face interactions
- Transfer of large text files

### Benefits of synchronous data transmission
- Low latency
- Reliable data transmission
- Efficient use of bandwidth
- Support for high-speed data rates

### Drawbacks of synchronous data transmission
- Requires dedicated communication channels
- More complex and expensive than asynchronous data transmission
- Not suitable for all types of data

### Conclusion
Synchronous data transmission is a reliable and efficient way of transferring data in real time. It is suitable for applications that require low latency, such as video conferencing and online gaming. However, it does require dedicated communication channels and is more complex and expensive than asynchronous data transmission.


## Questions 
- What if a control character is sent in text transmission?
> Data transparency - Each control character is preceded by DLE (Data Link Escape) and if a control character occurs in the body by any chance then it is not interpreted as such because it is not preceded by a DLE (If a DLE accidentally occurs in the body another DLE is inserted before it to signify that the upcoming bits are not control bits)

- Who decides which bits represent what?