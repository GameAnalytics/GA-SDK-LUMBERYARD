#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "gdi32.lib")

#include "StdAfx.h"
#include <platform_impl.h>
#include "GameAnalyticsGem.h"

#if USE_GAMEANALYTICS

#if defined(DARWIN) || defined(WIN32)
#include "GameAnalytics.h"
#elif defined(IOS)
#include "GameAnalyticsCpp.h"
#elif defined(ANDROID)
#include "GameAnalyticsJNI.h"
#endif

#include <vector>
#include <AzFramework/StringFunc/StringFunc.h>

#endif

namespace GameAnalytics
{
    string const GameAnalyticsGem::VERSION = "0.1.1";

    GameAnalyticsGem::GameAnalyticsGem() : CryHooksModule()
    {
        GameAnalyticsRequestBus::Handler::BusConnect();
    }
    GameAnalyticsGem::~GameAnalyticsGem()
    {
        GameAnalyticsRequestBus::Handler::BusDisconnect();
    }

    void GameAnalyticsGem::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
    {
        switch(event)
        {
            case ESYSTEM_EVENT_FULL_SHUTDOWN:
            case ESYSTEM_EVENT_FAST_SHUTDOWN:
#if USE_GAMEANALYTICS
#if defined(DARWIN) || defined(WIN32)
                gameanalytics::GameAnalytics::onStop();
#endif
#endif
                break;
        }
    }

#if USE_GAMEANALYTICS
    /**
    * GameAnalyticsRequestBus interface implementation
    */

    void GameAnalyticsGem::ConfigureAvailableCustomDimensions01(const AZStd::vector<string>& customDimensions)
    {
        LazyInitWritablePath();

        std::vector<std::string> dimensions;
        for(const string& dimension : customDimensions)
        {
            dimensions.push_back(dimension.c_str());
        }

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureAvailableCustomDimensions01(dimensions);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableCustomDimensions01(dimensions);
#elif defined(ANDROID)
        jni_configureAvailableCustomDimensions01(dimensions);
#endif
    }

    void GameAnalyticsGem::ConfigureAvailableCustomDimensions02(const AZStd::vector<string>& customDimensions)
    {
        LazyInitWritablePath();

        std::vector<std::string> dimensions;
        for(const string& dimension : customDimensions)
        {
            dimensions.push_back(dimension.c_str());
        }
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureAvailableCustomDimensions02(dimensions);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableCustomDimensions02(dimensions);
#elif defined(ANDROID)
        jni_configureAvailableCustomDimensions02(dimensions);
#endif
    }

    void GameAnalyticsGem::ConfigureAvailableCustomDimensions03(const AZStd::vector<string>& customDimensions)
    {
        LazyInitWritablePath();

        std::vector<std::string> dimensions;
        for(const string& dimension : customDimensions)
        {
            dimensions.push_back(dimension.c_str());
        }
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureAvailableCustomDimensions03(dimensions);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableCustomDimensions03(dimensions);
#elif defined(ANDROID)
        jni_configureAvailableCustomDimensions03(dimensions);
#endif
    }

    void GameAnalyticsGem::ConfigureAvailableResourceCurrencies(const AZStd::vector<string>& resourceCurrencies)
    {
        LazyInitWritablePath();

        std::vector<std::string> currencies;
        for(const string& currency : resourceCurrencies)
        {
            currencies.push_back(currency.c_str());
        }
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureAvailableResourceCurrencies(currencies);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableResourceCurrencies(currencies);
#elif defined(ANDROID)
        jni_configureAvailableResourceCurrencies(currencies);
#endif
    }

    void GameAnalyticsGem::ConfigureAvailableResourceItemTypes(const AZStd::vector<string>& resourceItemTypes)
    {
        LazyInitWritablePath();

        std::vector<std::string> itemTypes;
        for(const string& itemType : resourceItemTypes)
        {
            itemTypes.push_back(itemType.c_str());
        }
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureAvailableResourceItemTypes(itemTypes);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableResourceItemTypes(itemTypes);
#elif defined(ANDROID)
        jni_configureAvailableResourceItemTypes(itemTypes);
#endif
    }

    void GameAnalyticsGem::ConfigureBuild(const string& build)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureBuild(build.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::configureBuild(build.c_str());
#elif defined(ANDROID)
        jni_configureBuild(build.c_str());
#endif
    }

    void GameAnalyticsGem::ConfigureUserId(const string& uId)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureUserId(uId.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::configureUserId(uId.c_str());
#elif defined(ANDROID)
        jni_configureUserId(uId.c_str());
#endif
    }

    // initialize - starting SDK (need configuration before starting)
    void GameAnalyticsGem::Initialize(const string& gameKey, const string& gameSecret)
    {
        LazyInitWritablePath();

        string sdkVersion;
        sdkVersion.Format("lumberyard %s", VERSION.c_str());

        string engineVersion;
        const SFileVersion& fileVersion = gEnv->pSystem->GetFileVersion();
        engineVersion.Format("lumberyard %d.%d.%d", fileVersion[0], fileVersion[1], fileVersion[2]);

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::configureSdkGameEngineVersion(sdkVersion.c_str());
        gameanalytics::GameAnalytics::configureGameEngineVersion(engineVersion.c_str());
        gameanalytics::GameAnalytics::initialize(gameKey.c_str(), gameSecret.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::configureSdkGameEngineVersion(sdkVersion.c_str());
        GameAnalyticsCpp::configureGameEngineVersion(engineVersion.c_str());
        GameAnalyticsCpp::initialize(gameKey.c_str(), gameSecret.c_str());
#elif defined(ANDROID)
        jni_configureSdkGameEngineVersion(sdkVersion.c_str());
        jni_configureGameEngineVersion(engineVersion.c_str());
        jni_initialize(gameKey.c_str(), gameSecret.c_str());
#endif
    }

    // add events
    void GameAnalyticsGem::AddBusinessEvent(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str(), NULL);
#elif defined(ANDROID)
        jni_addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str());
#endif
    }

#if defined(IOS)
    void GameAnalyticsGem::AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt)
    {
        GameAnalyticsCpp::addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str(), receipt.c_str());
    }

    void GameAnalyticsGem::AddBusinessEventWithAutoFetchReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType)
    {
        GameAnalyticsCpp::addBusinessEventAndAutoFetchReceipt(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str());
    }
#elif defined(ANDROID)
    void GameAnalyticsGem::AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt, const string& signature)
    {
        jni_addBusinessEventWithReceipt(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str(), receipt.c_str(), "google_play", signature.c_str());
    }
#endif

    void GameAnalyticsGem::AddResourceEvent(EGAResourceFlowType flowType, const string& currency, float amount, const string&itemType, const string& itemId)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addResourceEvent(static_cast<gameanalytics::EGAResourceFlowType>(static_cast<int>(flowType)), currency.c_str(), amount, itemType.c_str(), itemId.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::addResourceEvent(static_cast<int>(flowType), currency.c_str(), amount, itemType.c_str(), itemId.c_str());
#elif defined(ANDROID)
        jni_addResourceEvent(static_cast<int>(flowType), currency.c_str(), amount, itemType.c_str(), itemId.c_str());
#endif
    }

    void GameAnalyticsGem::AddProgressionEvent(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addProgressionEvent(static_cast<gameanalytics::EGAProgressionStatus>(static_cast<int>(progressionStatus)), progression01.c_str(), progression02.c_str(), progression03.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::addProgressionEvent(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str());
#elif defined(ANDROID)
        jni_addProgressionEvent(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str());
#endif
    }

    void GameAnalyticsGem::AddProgressionEventWithScore(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03, int score)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addProgressionEvent(static_cast<gameanalytics::EGAProgressionStatus>(static_cast<int>(progressionStatus)), progression01.c_str(), progression02.c_str(), progression03.c_str(), score);
#elif defined(IOS)
        GameAnalyticsCpp::addProgressionEventWithScore(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str(), score);
#elif defined(ANDROID)
        jni_addProgressionEventWithScore(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str(), score);
#endif
    }

    void GameAnalyticsGem::AddDesignEvent(const string& eventId)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addDesignEvent(eventId.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::addDesignEvent(eventId.c_str());
#elif defined(ANDROID)
        jni_addDesignEvent(eventId.c_str());
#endif
    }

    void GameAnalyticsGem::AddDesignEventWithValue(const string& eventId, double value)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addDesignEvent(eventId.c_str(), value);
#elif defined(IOS)
        GameAnalyticsCpp::addDesignEventWithValue(eventId.c_str(), value);
#elif defined(ANDROID)
        jni_addDesignEventWithValue(eventId.c_str(), value);
#endif
    }

    void GameAnalyticsGem::AddErrorEvent(EGAErrorSeverity severity, const string& message)
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::addErrorEvent(static_cast<gameanalytics::EGAErrorSeverity>(static_cast<int>(severity)), message.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::addErrorEvent(static_cast<int>(severity), message.c_str());
#elif defined(ANDROID)
        jni_addErrorEvent(static_cast<int>(severity), message.c_str());
#endif
    }

    void GameAnalyticsGem::SetEnabledInfoLog(bool flag)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setEnabledInfoLog(flag);
#elif defined(IOS)
        GameAnalyticsCpp::setEnabledInfoLog(flag);
#elif defined(ANDROID)
        jni_setEnabledInfoLog(flag);
#endif
    }

    void GameAnalyticsGem::SetEnabledVerboseLog(bool flag)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setEnabledVerboseLog(flag);
#elif defined(IOS)
        GameAnalyticsCpp::setEnabledVerboseLog(flag);
#elif defined(ANDROID)
        jni_setEnabledVerboseLog(flag);
#endif
    }

    void GameAnalyticsGem::SetEnabledManualSessionHandling(bool flag)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setEnabledManualSessionHandling(flag);
#elif defined(IOS)
        GameAnalyticsCpp::setEnabledManualSessionHandling(flag);
#elif defined(ANDROID)
        jni_setEnabledManualSessionHandling(flag);
#endif
    }

    void GameAnalyticsGem::SetCustomDimension01(const string& dimension01)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setCustomDimension01(dimension01.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setCustomDimension01(dimension01.c_str());
#elif defined(ANDROID)
        jni_setCustomDimension01(dimension01.c_str());
#endif
    }

    void GameAnalyticsGem::SetCustomDimension02(const string& dimension02)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setCustomDimension02(dimension02.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setCustomDimension02(dimension02.c_str());
#elif defined(ANDROID)
        jni_setCustomDimension02(dimension02.c_str());
#endif
    }

    void GameAnalyticsGem::SetCustomDimension03(const string& dimension03)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setCustomDimension03(dimension03.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setCustomDimension03(dimension03.c_str());
#elif defined(ANDROID)
        jni_setCustomDimension03(dimension03.c_str());
#endif
    }

    void GameAnalyticsGem::SetFacebookId(const string& facebookId)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setFacebookId(facebookId.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setFacebookId(facebookId.c_str());
#elif defined(ANDROID)
        jni_setFacebookId(facebookId.c_str());
#endif
    }

    void GameAnalyticsGem::SetGender(EGAGender gender)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setGender(static_cast<gameanalytics::EGAGender>(static_cast<int>(gender)));
#elif defined(IOS)
        switch(gender)
        {
            case Male:
                GameAnalyticsCpp::setGender("male");
                break;

            case Female:
                GameAnalyticsCpp::setGender("female");
                break;
        }
#elif defined(ANDROID)
        jni_setGender(static_cast<int>(gender));
#endif
    }

    void GameAnalyticsGem::SetBirthYear(int birthYear)
    {
        LazyInitWritablePath();

#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::setBirthYear(birthYear);
#elif defined(IOS)
        GameAnalyticsCpp::setBirthYear(birthYear);
#elif defined(ANDROID)
        jni_setBirthYear(birthYear);
#endif
    }

    void GameAnalyticsGem::StartSession()
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::startSession();
#elif defined(IOS)
        GameAnalyticsCpp::startSession();
#elif defined(ANDROID)
        jni_startSession();
#endif
    }

    void GameAnalyticsGem::EndSession()
    {
#if defined(DARWIN) || defined(WIN32)
        gameanalytics::GameAnalytics::endSession();
#elif defined(IOS)
        GameAnalyticsCpp::endSession();
#elif defined(ANDROID)
        jni_endSession();
#endif
    }

    void GameAnalyticsGem::LazyInitWritablePath()
    {
        if(!this->isWritablePathInitialised)
        {
#if defined(DARWIN) || defined(WIN32)
            AZStd::string writablePath;
            AzFramework::StringFunc::Path::Join(gEnv->pFileIO->GetAlias("@user@"), "GameAnalytics", writablePath);
            gEnv->pCryPak->MakeDir(writablePath.c_str());
            gameanalytics::GameAnalytics::configureWritablePath(writablePath.c_str());
#endif
            this->isWritablePathInitialised = true;
        }
    }

#else // Dummy implementation for platforms that GameAnalytics does not support yet
    void GameAnalyticsGem::ConfigureAvailableCustomDimensions01(const AZStd::vector<string>& customDimensions)
    {
        CryLog("GameAnalytics::ConfigureAvailableCustomDimensions01: platform is not supported");
    }

    void GameAnalyticsGem::ConfigureAvailableCustomDimensions02(const AZStd::vector<string>& customDimensions)
    {
        CryLog("GameAnalytics::ConfigureAvailableCustomDimensions02: platform is not supported");
    }

    void GameAnalyticsGem::ConfigureAvailableCustomDimensions03(const AZStd::vector<string>& customDimensions)
    {
        CryLog("GameAnalytics::ConfigureAvailableCustomDimensions03: platform is not supported");
    }

    void GameAnalyticsGem::ConfigureAvailableResourceCurrencies(const AZStd::vector<string>& resourceCurrencies)
    {
        CryLog("GameAnalytics::ConfigureAvailableResourceCurrencies: platform is not supported");
    }

    void GameAnalyticsGem::ConfigureAvailableResourceItemTypes(const AZStd::vector<string>& resourceItemTypes)
    {
        CryLog("GameAnalytics::ConfigureAvailableResourceItemTypes: platform is not supported");
    }

    void GameAnalyticsGem::ConfigureBuild(const string& build)
    {
        CryLog("GameAnalytics::ConfigureBuild: platform is not supported");
    }

    void GameAnalyticsGem::ConfigureUserId(const string& uId)
    {
        CryLog("GameAnalytics::ConfigureUserId: platform is not supported");
    }

    // initialize - starting SDK (need configuration before starting)
    void GameAnalyticsGem::Initialize(const string& gameKey, const string& gameSecret)
    {
        CryLog("GameAnalytics::Initialize: platform is not supported");
    }

    // add events
    void GameAnalyticsGem::AddBusinessEvent(const string& currency,
                                             int amount,
                                             const string& itemType,
                                             const string& itemId,
                                             const string& cartType)
    {
        CryLog("GameAnalytics::AddBusinessEvent: platform is not supported");
    }

    void GameAnalyticsGem::AddResourceEvent(EGAResourceFlowType flowType,
                                             const string& currency,
                                             float amount,
                                             const string&itemType,
                                             const string& itemId)
    {
        CryLog("GameAnalytics::AddResourceEvent: platform is not supported");
    }

    void GameAnalyticsGem::AddProgressionEvent(EGAProgressionStatus progressionStatus,
                                                         const string& progression01,
                                                         const string& progression02,
                                                         const string& progression03)
    {
        CryLog("GameAnalytics::AddProgressionEvent: platform is not supported");
    }

    void GameAnalyticsGem::AddProgressionEventWithScore(EGAProgressionStatus progressionStatus,
                                                         const string& progression01,
                                                         const string& progression02,
                                                         const string& progression03,
                                                         int score)
    {
        CryLog("GameAnalytics::AddProgressionEvent: platform is not supported");
    }

    void GameAnalyticsGem::AddDesignEvent(const string& eventId)
    {
        CryLog("GameAnalytics::AddDesignEvent: platform is not supported");
    }

    void GameAnalyticsGem::AddDesignEventWithValue(const string& eventId, double value)
    {
        CryLog("GameAnalytics::AddDesignEvent: platform is not supported");
    }

    void GameAnalyticsGem::AddErrorEvent(EGAErrorSeverity severity, const string& message)
    {
        CryLog("GameAnalytics::AddErrorEvent: platform is not supported");
    }

    void GameAnalyticsGem::SetEnabledInfoLog(bool flag)
    {
        CryLog("GameAnalytics::SetEnabledInfoLog: platform is not supported");
    }

    void GameAnalyticsGem::SetEnabledVerboseLog(bool flag)
    {
        CryLog("GameAnalytics::SetEnabledVerboseLog: platform is not supported");
    }

    void GameAnalyticsGem::SetEnabledManualSessionHandling(bool flag)
    {
        CryLog("GameAnalytics::SetEnabledManualSessionHandling: platform is not supported");
    }

    void GameAnalyticsGem::SetCustomDimension01(const string& dimension01)
    {
        CryLog("GameAnalytics::SetCustomDimension01: platform is not supported");
    }

    void GameAnalyticsGem::SetCustomDimension02(const string& dimension02)
    {
        CryLog("GameAnalytics::SetCustomDimension02: platform is not supported");
    }

    void GameAnalyticsGem::SetCustomDimension03(const string& dimension03)
    {
        CryLog("GameAnalytics::SetCustomDimension03: platform is not supported");
    }

    void GameAnalyticsGem::SetFacebookId(const string& facebookId)
    {
        CryLog("GameAnalytics::SetFacebookId: platform is not supported");
    }

    void GameAnalyticsGem::SetGender(EGAGender gender)
    {
        CryLog("GameAnalytics::SetGender: platform is not supported");
    }

    void GameAnalyticsGem::SetBirthYear(int birthYear)
    {
        CryLog("GameAnalytics::SetBirthYear: platform is not supported");
    }

    void GameAnalyticsGem::StartSession()
    {
        CryLog("GameAnalytics::StartSession: platform is not supported");
    }

    void GameAnalyticsGem::EndSession()
    {
        CryLog("GameAnalytics::EndSession: platform is not supported");
    }

    void GameAnalyticsGem::LazyInitWritablePath()
    {

    }

#endif // USE_GAMEANALYTICS
}

AZ_DECLARE_MODULE_CLASS(GameAnalytics_20e77666d03d4950bad1195511145059, GameAnalytics::GameAnalyticsGem)
