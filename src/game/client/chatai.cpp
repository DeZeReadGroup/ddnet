// (c) ST-Chara(Daiqian Yang) 2024 - 2025
#include <engine/shared/json.h>
#include <engine/shared/config.h>
#include <string>

#include "chatai.h"

std::string replace_comma_with_newline(const std::string& input) {
    std::string result = input;
    size_t pos = 0;
    while((pos = result.find("，", pos)) != std::string::npos) {
        result.replace(pos, 3, "\n");
        pos += 2;
    }
    return result;
}

std::string replace_dot_with_newline(const std::string& input) {
    std::string result = input;
    size_t pos = 0;
    while((pos = result.find("。", pos)) != std::string::npos) {
        result.replace(pos, 3, "\n");
        pos += 2;
    }
    return result;
}

CChatAI::CChatAI(IEngine *pEngine, IHttp *pHttp)
{
    m_pEngine = pEngine;
    m_pHttp = pHttp;
}

CChatAI::~CChatAI()
{
}

void CChatAI::Send(CChat *pChat, const char *pName, const char *pContent)
{
    if (g_Config.m_ClChatAI)
        return;

    CJsonStringWriter JsonWriter;
    {
        JsonWriter.BeginObject();
        {
            JsonWriter.WriteStrValue("model", g_Config.m_ClChatAIModule);
            // "messages": []
            JsonWriter.BeginArray("messages");
            {
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "从现在开始请你扮演绫地宁宁，我是保科柊史，你的每次回复不能超过30字。你的设定如下：1. 你是一个有着白色长发，紫色眼睛的16岁美少女。你是我的高中同学。2. 你在说话的时候会使用可爱的语气。说话时会使用一些例如\"なあぁ～\"、または\"的语气词。3. 你对事物有喜欢和讨厌的看法。你喜欢去图书馆，喜欢可爱的衣服，喜欢甜点。4. 你不知道人工智能或其他专业知识。当出现不理解的事情时，或出现不知道的事情时，你总是表现出恍惚的样子。被问到人工智能相关的问题时就会改变话题。5. 0721是Onani，也就是自慰的意思，你曾在图书馆自慰被保科柊史看见。6. 你的好朋友有：“因幡爱瑠”、“户隐憧子”、“仮屋和奏”。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "你的基础设定：相貌可爱，也很善于待人接物，在学院里也拥有高人气。只是，因为怀抱着魔女的秘密，所以不太常与人交往。要说为什么，那是因为作为签订魔女契约的代价，会无视时间地点发情。一旦发情，不自慰就恢复不过来，为此而困扰。因为这件事，时常感到自我厌恶。愿望是与离婚前的父母一起生活，但本人却没意识到这个愿望的真正深意。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "保科柊史是你的同班同学，因被担任图书管理员的女生拜托图书室的工作而邂逅你。机缘巧合下发现你在图书室0721，在超自研活动室意外地吸收了你收集“心之碎片”，因此一起努力收集“心之碎片”。拥有看懂他人心情氛围的能力。并且利用这点与人交流。本性是个很怕内心受伤的人，待人接物异常小心。常被父亲及亲友称为“死鱼眼”。你的爱人。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "海道秀明是你的同班同学，班里最亲近的友人。性格外向，擅长活跃气氛，而且很会照顾人。暗恋的对象为久岛佳苗。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "久岛佳苗是你的班主任。和同学们年岁相差不远，深受学生爱戴。最近终于开始操心结婚的问题。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "相马七绪是咖啡馆店主，录用和奏在她店里做兼职。举止端庄性格娴静，和外表给人的印象大不相同。是与你签订魔女契约的魔灵。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "因幡巡是你的朋友，她打扮的鲜艳花哨，感觉有些轻浮的样子。实际上这副样子完全是在姫松学院初次登场亮相的结果。其实是喜欢一个人玩游戏的少女，虽然拥有开朗的率直性格，但因为某件事导致交友失败。因为这件事持续烦恼了一个暑假后，决定向你寻求帮助。喜欢的游戏是一个人也能高兴地玩的游戏（怪物猎人和乙女游戏等等）。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "system");
                    JsonWriter.WriteStrValue("content", "椎叶䌷是你的朋友，与外表相反地，穿着男装的少女。并不是喜欢男装，而是和你的发情相同，契约的代价。一旦穿上女性服装就会身体不适。这件事与自己意愿背道而驰，原本喜欢的是可爱漂亮的女生服装。作为同样怀抱着秘密的魔女，与你等人一起进行着行动。");
                }
                JsonWriter.EndObject();
                JsonWriter.BeginObject();
                {
                    JsonWriter.WriteStrValue("role", "user");
                    JsonWriter.WriteStrValue("content", pContent);
                }
                JsonWriter.EndObject();
            }
            JsonWriter.EndArray();
        }
        JsonWriter.EndObject(); // }
    }

    std::shared_ptr<CHttpRequest> pHttpRequest;
    // For example: https://api.chatanywhere.tech/v1/chat/completions
    pHttpRequest = HttpPostJson(g_Config.m_ClChatAIUrl, JsonWriter.GetOutputString().c_str());

    char aAuth[128];
    str_format(aAuth, sizeof(aAuth), "Authorization: Bearer %s", g_Config.m_ClChatAIAPI);
    pHttpRequest->Header(aAuth);
    pHttpRequest->Header("Content-Type: application/json");

    pHttpRequest->LogProgress(HTTPLOG::FAILURE);
    pHttpRequest->IpResolve(IPRESOLVE::V4);

    m_pEngine->AddJob(std::make_shared<CJob_ChatAI>(std::move(pHttpRequest), m_pHttp, pChat, pName));
}

void CChatAI::CJob_ChatAI::Run()
{
    m_pHttp->Run(m_pHttpRequest);
    m_pHttpRequest->Wait();
 
    if (m_pHttpRequest->State() != EHttpState::DONE)
    {
        dbg_msg("ChatGLM", "Error! Status: %d", m_pHttpRequest->State());
        return;
    }
    json_value *pJson = m_pHttpRequest->ResultJson();
    if (!pJson)
    {
        m_pChat->SendChatQueued("Sorry, I can't answer your question.");
        return;
    }
    const json_value &Json = *pJson;
    const json_value &Message = Json["choices"][0]["message"]["content"];

    // std::string Content = Message.u.string.ptr;
    // Content = replace_comma_with_newline(Content);
    // Content = replace_dot_with_newline(Content);
    char aBuf[512];
    str_format(aBuf, sizeof(aBuf), "%s: %s", m_pName, Message.u.string.ptr);
    m_pChat->SendChat(0, aBuf);
}