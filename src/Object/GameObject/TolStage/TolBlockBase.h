#pragma once
#include "cinder/app/App.h"
#include "../GameObject.h"


namespace tol
{
    class TolBlockBase : public GameObject
    {
        // ブロックごとに持っている何かしらの特別な動き
        virtual void action() {}
    };
}
