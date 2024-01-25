# Rules-Based-Chabot

**Title :**
Design and implement a rules-based Chabot using socket programming, where the server
is responsible for handling client queries based on a predefined set of rules and
descriptions. The server should incorporate the following components: Define Intents,
Rule-based Responses, Error Handling, and Feedback Mechanism. The goal is to have the
server respond with the appropriate description based on the client's input.

**How to Compile**

To run the single client systems, open two terminals and compile using **g++ std=c++11 filename.cpp -o filename**

**Requirements :**

1. Socket Communication:
 Implement a server and a client using socket programming to establish
communication.
2. Define Intents:
 Identify and define at least three distinct user intents. Examples could
include greetings, product information inquiries, or FAQs.
3. Rule-based Responses:
 Create rules for each intent to trigger specific responses. These rules should
be based on keywords, patterns, or regular expressions.
4. Error Handling:
 Implement rules to handle situations where the server doesn't understand
the client's input or encounters errors. Provide appropriate error responses.
5. Feedback Mechanism:
 Include a mechanism for the client to provide feedback on the Chabot’s
responses.

**Example :**

**Define Intents:**
1) Greetings:
 Recognize user greetings like "hello," "hi," or "hey."
2) Product Information:
 Identify queries related to product information, such as "Tell me about product X" or "What features does product Y have?"
3) FAQs:
 Handle frequently asked questions like "What are your business hours?" or "How can I contact support?"

**Rule-based Responses:**
1) Greetings:
   
 Rule: If user input contains greetings, respond with a friendly greeting.
 
Example:

 User: "Hello!"

 Chabot: "Hi there! How can I assist you today?"
 
2) Product Information:

 Rule: If the user asks about product information, provide relevant details.
 
 Example:
 
 User: "Tell me about your latest smartphone."
 
 Chabot: "Our latest smartphone is the XYZ model, featuring a high-resolution camera and a long-lasting battery."

3) FAQs:
   
 Rule: If the user asks a common question, respond with the appropriate answer.
 
 Example:
 
 User: "What are your business hours?"
 
 Chabot: "Our business hours are Monday to Friday, 9:00 AM to 5:00 PM."
 
**Error Handling:**

Rule: If the user input is unclear or doesn't match any predefined intent, respond with a clarification message.

 Example:
 
 User: "Tell me stuff."
 
 Chabot: "I'm sorry, I didn't understand. Could you please provide more details or ask a specific question?"
 
**Feedback Mechanism:**

Rule: If the user provides feedback, acknowledge and thank them.

Example:

 User: "Your service is great!"
 
 Chabot: "Thank you for your kind words! We're here to help. Is there anything specific you'd like assistance with?"
 
**Example Interaction:**

1. User: "Hi!"
   
   Chabot: "Hello there! How can I assist you today?"
   
3. User: "What features does your latest laptop have?"
   
   Chabot: "Our latest laptop comes with a high-performance processor, a sleek design, and a long-lasting battery."
   
5. User: "What's your return policy?"

   Chabot: "Our return policy allows for returns within 30 days of purchase.Please visit our website for more details."
   
7. User: "Tell me stuff."
   
   Chabot: "I'm sorry, I didn't understand. Could you please provide more details or ask a specific question?"
   
9. User: "Your service is great!"
   
   Chabot: "Thank you for your kind words! We're here to help. Is there anything specific you'd like assistance with?"

This example illustrates how a rules-based Chabot uses predefined rules to handle different
user inputs and generate appropriate responses. The rules are designed to cover greetings,
specific queries, FAQs, and error handling.


**Sample Output**

![photo_2024-01-25_16-26-36](https://github.com/sangdeepganvir/-Rules-Based-Chabot/assets/41817210/91584afd-b429-49e3-9e61-119a61bb3bbc)
