#pragma once
#include "../TextureRenderer/TextureRenderer.h"


namespace tol
{
    class ButtonBase : public tol::TextureRenderer
    {
    public:
        ButtonBase() {}
        ButtonBase(const std::string& texture_name);
        ButtonBase(const std::string& texture_name, const std::function<void()>& func);

        void awake()override;

        void setCallBackFunc(const std::function<void()>& func) { callback_func = func; }

        void setIsSelect(const bool& value) { is_select = value; }
        bool getIsSelect() { return is_select; }

    protected:

        ci::Vec2f mouse_position;
        std::function<void()> callback_func;    // ボタンを選択した時に呼び出される関数
        float radius;                           // 円のボタンの場合の半径
        bool is_select;                         // 選ばれている、またはマウスが入っている場合はtrue
        bool current_is_select;                 // 現在のselectフラグを保存

    };
}
