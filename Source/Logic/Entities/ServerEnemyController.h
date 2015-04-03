#ifndef _SERVER_ENEMY_CONTROLLER_H_
#define _SERVER_ENEMY_CONTROLLER_H_

#include "ServerNetworkController.h"
#include "../Artificial Intelligence/Behaviour.h"
#include "../Event.h"
#include "../../Engine/VEntity.h"

using Marx::Entity;

class Behaviour;

class ServerEnemyController : public ServerNetworkController
{
    public:
        ServerEnemyController(Behaviour *behaviour);
        virtual ~ServerEnemyController();
        void setEntity(Entity*);
        void init();
        void updateBehaviour(float deltaTime);

    private:
        Behaviour *behaviour;
        bool moving;
        Entity* _currEntity;
};

#endif
