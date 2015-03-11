#ifndef SERVER_H_
#define SERVER_H_

#include <vector>

namespace Networking
{
    class Session;
    class SendProcess;
    class ReceiveProcess;

    class Server
    {
    public:
        /**
         * constructs a new {Server}.
         */
        Server();

        /**
         * Clean up the Server on destruction.
         */
        virtual ~Server();

        /**
         * initializes the server to listen for incoming connections on the given port
         *
         * @param  port to connect to
         *
         * @return integer indicating the outcome of the operation
         */
        int startServer(short port);

        /**
         * stops server
         *
         * @return integer indicating the outcome of the operation
         */
        int stopServer();

        /**
         * function to be overridden by children
         *
         * @param  session
         */
        virtual void onConnect(Session* session);

    private:
        static void* listeningThread(void* params);
        int listeningSocket;
        std::vector<Session*> sessions;
        SendProcess *sendProc;
        ReceiveProcess *receiveProc;
    };
}

#endif
