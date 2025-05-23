# Part 1: Let's Have a Chat

Entering lab, you may have noticed something interesting running on the projector. We've started up a demonstration of the next PA to play around with.
For the next PA, you'll be creating your own chatroom server, where users can send and react to other's messages.

We've included a client on the `ieng6` machines that you can use to communicate in our chatroom.

We can run our chat-client with: (where `MACHINE` is `ieng6-201` for Joe's lab, or `ieng6-202` for Aaron's lab)
```
/home/linux/ieng6/cs29fa24/public/chat-client USERNAME MACHINE 8000
```

**Task:** 
1. Choose a username and send a message to your lab room's chat server.
2. Try reacting to a member of your lab group's message. Try reacting with an emoji 😁
3. **In your notes:** Add a screenshot of your message and reaction.
---
The client is cool, but there are many other ways we can also interact with the chat server:
 In the past we've been using `curl` primarily to download single files from the internet. We can also use `curl` to send messages!

To see all the messages of the chat server we can curl the url:
```
curl 'MACHINE.ucsd.edu:8000/chats'
```


To send a message to the chat server, we can curl the url:
```
curl 'MACHINE.ucsd.edu:8000/post?user=USERNAME&message=MESSAGE'
```
**Task:** 

3.  Try sending a message to the chatroom server using `curl`


To react to another user's message, we can curl the url:
```
curl 'MACHINE.ucsd.edu:8000/react?user=USERNAME&message=REACTION&id=ID'
```
`REACTION` can be any 16 byte message and `ID` is the id of the message you wish to react to. 

**Task:** 

3. Try reacting to your group member's message from your web browser (Chrome, Safari, Firefox, etc.)
4. **In your notes:** Add a screenshot from your web browser of `MACHINE.ucsd.edu:8000/chats`.
