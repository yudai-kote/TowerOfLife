#include "GameObjectEntities.h"


tol::GameObjectEntities::GameObjectEntities()
{
}

tol::GameObjectEntities::~GameObjectEntities()
{
    //allDestroy();
}

void tol::GameObjectEntities::componentsUpdate()
{
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->componentsUpdate();
    }
}

void tol::GameObjectEntities::drawBegin()
{
    for (const auto& it : gameobjects)
    {
        it.second->drawBegin();
    }
}

void tol::GameObjectEntities::drawEnd()
{
    for (const auto& it : gameobjects)
    {
        it.second->drawEnd();
    }
}

void tol::GameObjectEntities::componentsDraw()
{
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->componentsDraw();
    }
}

void tol::GameObjectEntities::componentsDestory()
{
    for (const auto& it : gameobjects)
    {
        it.second->componentsDestroy();
    }
}


void tol::GameObjectEntities::setupGameObject()
{
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->setup();
    }
}

void tol::GameObjectEntities::updateGameObject()
{
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        if (!it.second->getIsUpdateActive())continue;
        it.second->componentsUpdate();
        it.second->update();
    }
}

void tol::GameObjectEntities::laterUpdateGameObject()
{
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->laterUpdate();
    }
}

void tol::GameObjectEntities::drawGameObject()
{
    ci::gl::pushModelView();
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->drawBegin();
        it.second->pushModelView();

        it.second->componentsDraw();
        it.second->draw();

        it.second->popModelView();
        it.second->drawEnd();

    }
    ci::gl::popModelView();
}

void tol::GameObjectEntities::transDrawGameObject()
{
    ci::gl::pushModelView();
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->transDraw();
    }
    ci::gl::popModelView();
}

void tol::GameObjectEntities::laterDrawGameObject()
{
    ci::gl::pushModelView();
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->laterDraw();
    }
    ci::gl::popModelView();
}

void tol::GameObjectEntities::transLaterDrawGameObject()
{
    ci::gl::pushModelView();
    for (const auto& it : gameobjects)
    {
        if (!it.second->getActive())continue;
        it.second->transLaterDraw();
    }
    ci::gl::popModelView();
}

void tol::GameObjectEntities::allDestroy()
{
    for (auto it : gameobjects)
    {
        it.second->destory();
        it.second->componentsDestroy();
    }
    gameobjects.clear();
}