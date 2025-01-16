#ifndef ENGINE_SHARED_CHATGLM_H
#define ENGINE_SHARED_CHATGLM
#include <engine/engine.h>
#include <engine/shared/http.h>
#include <engine/shared/jsonwriter.h>
#include <game/client/components/chat.h>

class CChatAI
{
private:
    IEngine *m_pEngine;
    IHttp *m_pHttp;

public:
    CChatAI(IEngine *pEngine, IHttp *pHttp);
    ~CChatAI();

    void Send(CChat *pChat, const char *pName, const char *pContent);

    class CJob_ChatAI : public IJob
    {
        std::shared_ptr<CHttpRequest> m_pHttpRequest;
        IHttp *m_pHttp;
        CChat *m_pChat;
        const char *m_pName;
        void Run() override;

    public:
        CJob_ChatAI(std::shared_ptr<CHttpRequest> &&pHttpRequest, IHttp *pHttp, CChat *pChat, const char *pName)
        {
            m_pHttpRequest = std::move(pHttpRequest);
            m_pHttp = pHttp;
            m_pChat = pChat;
            m_pName = pName;
        }
        virtual ~CJob_ChatAI() = default;
    };
};

#endif // !