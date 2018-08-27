#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "gdi32.lib")

#include "StdAfx.h"
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "GameAnalyticsSystemComponent.h"

#if USE_GAMEANALYTICS

#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
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
    string const GameAnalyticsSystemComponent::VERSION = "2.0.1";

    void GameAnalyticsSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<GameAnalyticsSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<GameAnalyticsSystemComponent>("GameAnalytics", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void GameAnalyticsSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("GameAnalyticsService"));
    }

    void GameAnalyticsSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("GameAnalyticsService"));
    }

    void GameAnalyticsSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void GameAnalyticsSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void GameAnalyticsSystemComponent::Init()
    {
    }

    void GameAnalyticsSystemComponent::Activate()
    {
        GameAnalyticsRequestBus::Handler::BusConnect();
    }

    void GameAnalyticsSystemComponent::Deactivate()
    {
        GameAnalyticsRequestBus::Handler::BusDisconnect();
    }

#if USE_GAMEANALYTICS
    /**
    * GameAnalyticsRequestBus interface implementation
    */

    void GameAnalyticsSystemComponent::ConfigureAvailableCustomDimensions01(const AZStd::vector<string>& customDimensions)
    {
        std::vector<std::string> dimensions;
        for(const string& dimension : customDimensions)
        {
            dimensions.push_back(dimension.c_str());
        }

#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureAvailableCustomDimensions01(dimensions);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableCustomDimensions01(dimensions);
#elif defined(ANDROID)
        jni_configureAvailableCustomDimensions01(dimensions);
#endif
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableCustomDimensions02(const AZStd::vector<string>& customDimensions)
    {
        std::vector<std::string> dimensions;
        for(const string& dimension : customDimensions)
        {
            dimensions.push_back(dimension.c_str());
        }
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureAvailableCustomDimensions02(dimensions);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableCustomDimensions02(dimensions);
#elif defined(ANDROID)
        jni_configureAvailableCustomDimensions02(dimensions);
#endif
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableCustomDimensions03(const AZStd::vector<string>& customDimensions)
    {
        std::vector<std::string> dimensions;
        for(const string& dimension : customDimensions)
        {
            dimensions.push_back(dimension.c_str());
        }
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureAvailableCustomDimensions03(dimensions);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableCustomDimensions03(dimensions);
#elif defined(ANDROID)
        jni_configureAvailableCustomDimensions03(dimensions);
#endif
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableResourceCurrencies(const AZStd::vector<string>& resourceCurrencies)
    {
        std::vector<std::string> currencies;
        for(const string& currency : resourceCurrencies)
        {
            currencies.push_back(currency.c_str());
        }
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureAvailableResourceCurrencies(currencies);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableResourceCurrencies(currencies);
#elif defined(ANDROID)
        jni_configureAvailableResourceCurrencies(currencies);
#endif
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableResourceItemTypes(const AZStd::vector<string>& resourceItemTypes)
    {
        std::vector<std::string> itemTypes;
        for(const string& itemType : resourceItemTypes)
        {
            itemTypes.push_back(itemType.c_str());
        }
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureAvailableResourceItemTypes(itemTypes);
#elif defined(IOS)
        GameAnalyticsCpp::configureAvailableResourceItemTypes(itemTypes);
#elif defined(ANDROID)
        jni_configureAvailableResourceItemTypes(itemTypes);
#endif
    }

    void GameAnalyticsSystemComponent::ConfigureBuild(const string& build)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureBuild(build.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::configureBuild(build.c_str());
#elif defined(ANDROID)
        jni_configureBuild(build.c_str());
#endif
    }

    void GameAnalyticsSystemComponent::ConfigureUserId(const string& uId)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::configureUserId(uId.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::configureUserId(uId.c_str());
#elif defined(ANDROID)
        jni_configureUserId(uId.c_str());
#endif
    }

    // initialize - starting SDK (need configuration before starting)
    void GameAnalyticsSystemComponent::Initialize(const string& gameKey, const string& gameSecret)
    {
        string sdkVersion;
        sdkVersion.Format("lumberyard %s", VERSION.c_str());

        string engineVersion;
        const SFileVersion& fileVersion = gEnv->pSystem->GetFileVersion();
        engineVersion.Format("lumberyard %d.%d.%d", fileVersion.v[3], fileVersion.v[2], fileVersion.v[1]);

#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
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
    void GameAnalyticsSystemComponent::AddBusinessEvent(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str()/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str(), NULL/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str()/*, fields.c_str()*/);
#endif
    }

#if defined(IOS)
    void GameAnalyticsGem::AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt/*, const string& fields*/)
    {
        GameAnalyticsCpp::addBusinessEvent(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str(), receipt.c_str()/*, fields.c_str()*/);
    }

    void GameAnalyticsGem::AddBusinessEventWithAutoFetchReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType/*, const string& fields*/)
    {
        GameAnalyticsCpp::addBusinessEventAndAutoFetchReceipt(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str()/*, fields.c_str()*/);
    }
#elif defined(ANDROID)
    void GameAnalyticsGem::AddBusinessEventWithReceipt(const string& currency, int amount, const string& itemType, const string& itemId, const string& cartType, const string& receipt, const string& signature/*, const string& fields*/)
    {
        jni_addBusinessEventWithReceipt(currency.c_str(), amount, itemType.c_str(), itemId.c_str(), cartType.c_str(), receipt.c_str(), "google_play", signature.c_str()/*, fields.c_str()*/);
    }
#endif

    void GameAnalyticsSystemComponent::AddResourceEvent(EGAResourceFlowType flowType, const string& currency, float amount, const string&itemType, const string& itemId/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addResourceEvent(static_cast<gameanalytics::EGAResourceFlowType>(static_cast<int>(flowType)), currency.c_str(), amount, itemType.c_str(), itemId.c_str()/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addResourceEvent(static_cast<int>(flowType), currency.c_str(), amount, itemType.c_str(), itemId.c_str()/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addResourceEvent(static_cast<int>(flowType), currency.c_str(), amount, itemType.c_str(), itemId.c_str()/*, fields.c_str()*/);
#endif
    }

    void GameAnalyticsSystemComponent::AddProgressionEvent(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addProgressionEvent(static_cast<gameanalytics::EGAProgressionStatus>(static_cast<int>(progressionStatus)), progression01.c_str(), progression02.c_str(), progression03.c_str()/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addProgressionEvent(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str()/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addProgressionEvent(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str()/*, fields.c_str()*/);
#endif
    }

    void GameAnalyticsSystemComponent::AddProgressionEventWithScore(EGAProgressionStatus progressionStatus, const string& progression01, const string& progression02, const string& progression03, int score/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addProgressionEvent(static_cast<gameanalytics::EGAProgressionStatus>(static_cast<int>(progressionStatus)), progression01.c_str(), progression02.c_str(), progression03.c_str(), score/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addProgressionEventWithScore(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str(), score/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addProgressionEventWithScore(static_cast<int>(progressionStatus), progression01.c_str(), progression02.c_str(), progression03.c_str(), score/*, fields.c_str()*/);
#endif
    }

    void GameAnalyticsSystemComponent::AddDesignEvent(const string& eventId/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addDesignEvent(eventId.c_str()/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addDesignEvent(eventId.c_str()/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addDesignEvent(eventId.c_str()/*, fields.c_str()*/);
#endif
    }

    void GameAnalyticsSystemComponent::AddDesignEventWithValue(const string& eventId, double value/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addDesignEvent(eventId.c_str(), value/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addDesignEventWithValue(eventId.c_str(), value/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addDesignEventWithValue(eventId.c_str(), value/*, fields.c_str()*/);
#endif
    }

    void GameAnalyticsSystemComponent::AddErrorEvent(EGAErrorSeverity severity, const string& message/*, const string& fields*/)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::addErrorEvent(static_cast<gameanalytics::EGAErrorSeverity>(static_cast<int>(severity)), message.c_str()/*, fields.c_str()*/);
#elif defined(IOS)
        GameAnalyticsCpp::addErrorEvent(static_cast<int>(severity), message.c_str()/*, fields.c_str()*/);
#elif defined(ANDROID)
        jni_addErrorEvent(static_cast<int>(severity), message.c_str()/*, fields.c_str()*/);
#endif
    }

    void GameAnalyticsSystemComponent::SetEnabledInfoLog(bool flag)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setEnabledInfoLog(flag);
#elif defined(IOS)
        GameAnalyticsCpp::setEnabledInfoLog(flag);
#elif defined(ANDROID)
        jni_setEnabledInfoLog(flag);
#endif
    }

    void GameAnalyticsSystemComponent::SetEnabledVerboseLog(bool flag)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setEnabledVerboseLog(flag);
#elif defined(IOS)
        GameAnalyticsCpp::setEnabledVerboseLog(flag);
#elif defined(ANDROID)
        jni_setEnabledVerboseLog(flag);
#endif
    }

    void GameAnalyticsSystemComponent::SetEnabledManualSessionHandling(bool flag)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setEnabledManualSessionHandling(flag);
#elif defined(IOS)
        GameAnalyticsCpp::setEnabledManualSessionHandling(flag);
#elif defined(ANDROID)
        jni_setEnabledManualSessionHandling(flag);
#endif
    }

    void GameAnalyticsSystemComponent::SetCustomDimension01(const string& dimension01)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setCustomDimension01(dimension01.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setCustomDimension01(dimension01.c_str());
#elif defined(ANDROID)
        jni_setCustomDimension01(dimension01.c_str());
#endif
    }

    void GameAnalyticsSystemComponent::SetCustomDimension02(const string& dimension02)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setCustomDimension02(dimension02.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setCustomDimension02(dimension02.c_str());
#elif defined(ANDROID)
        jni_setCustomDimension02(dimension02.c_str());
#endif
    }

    void GameAnalyticsSystemComponent::SetCustomDimension03(const string& dimension03)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setCustomDimension03(dimension03.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setCustomDimension03(dimension03.c_str());
#elif defined(ANDROID)
        jni_setCustomDimension03(dimension03.c_str());
#endif
    }

    void GameAnalyticsSystemComponent::SetFacebookId(const string& facebookId)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setFacebookId(facebookId.c_str());
#elif defined(IOS)
        GameAnalyticsCpp::setFacebookId(facebookId.c_str());
#elif defined(ANDROID)
        jni_setFacebookId(facebookId.c_str());
#endif
    }

    void GameAnalyticsSystemComponent::SetGender(EGAGender gender)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
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

    void GameAnalyticsSystemComponent::SetBirthYear(int birthYear)
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::setBirthYear(birthYear);
#elif defined(IOS)
        GameAnalyticsCpp::setBirthYear(birthYear);
#elif defined(ANDROID)
        jni_setBirthYear(birthYear);
#endif
    }

    void GameAnalyticsSystemComponent::StartSession()
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::startSession();
#elif defined(IOS)
        GameAnalyticsCpp::startSession();
#elif defined(ANDROID)
        jni_startSession();
#endif
    }

    void GameAnalyticsSystemComponent::EndSession()
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        gameanalytics::GameAnalytics::endSession();
#elif defined(IOS)
        GameAnalyticsCpp::endSession();
#elif defined(ANDROID)
        jni_endSession();
#endif
    }

    string GameAnalyticsSystemComponent::GetCommandCenterValueAsString(const string& key)
    {
#if defined(LINUX)
        return gameanalytics::GameAnalytics::getCommandCenterValueAsString(key.c_str());
#elif defined(DARWIN) || defined(WIN32)
        return gameanalytics::GameAnalytics::getCommandCenterValueAsString(key.c_str()).c_str();
#elif defined(IOS)
        return GameAnalyticsCpp::getCommandCenterValueAsString(key.c_str());
#elif defined(ANDROID)
        return jni_getCommandCenterValueAsString(key.c_str());
#endif
    }

    string GameAnalyticsSystemComponent::GetCommandCenterValueAsStringWithDefaultValue(const string& key, const string& defaultValue)
    {
#if defined(LINUX)
        return gameanalytics::GameAnalytics::getCommandCenterValueAsString(key.c_str(), defaultValue.c_str());
#elif defined(DARWIN) || defined(WIN32)
        return gameanalytics::GameAnalytics::getCommandCenterValueAsString(key.c_str(), defaultValue.c_str()).c_str();
#elif defined(IOS)
        return GameAnalyticsCpp::getCommandCenterValueAsString(key.c_str(), defaultValue.c_str());
#elif defined(ANDROID)
        return jni_getCommandCenterValueAsStringWithDefaultValue(key.c_str(), defaultValue.c_str());
#endif
    }

    bool GameAnalyticsSystemComponent::IsCommandCenterReady()
    {
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
        return gameanalytics::GameAnalytics::isCommandCenterReady();
#elif defined(IOS)
        return GameAnalyticsCpp::isCommandCenterReady();
#elif defined(ANDROID)
        return jni_isCommandCenterReady();
#endif
    }

    string GameAnalyticsSystemComponent::GetConfigurationsContentAsString()
    {
#if defined(LINUX)
        return gameanalytics::GameAnalytics::getConfigurationsContentAsString();
#elif defined(DARWIN) || defined(WIN32)
        return gameanalytics::GameAnalytics::getConfigurationsContentAsString().c_str();
#elif defined(IOS)
        return GameAnalyticsCpp::getConfigurationsContentAsString();
#elif defined(ANDROID)
        return jni_getConfigurationsContentAsString();
#endif
    }

#else // Dummy implementation for platforms that GameAnalytics does not support yet
    void GameAnalyticsSystemComponent::ConfigureAvailableCustomDimensions01(const AZStd::vector<string>& customDimensions)
    {
        CryLog("GameAnalytics::ConfigureAvailableCustomDimensions01: platform is not supported");
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableCustomDimensions02(const AZStd::vector<string>& customDimensions)
    {
        CryLog("GameAnalytics::ConfigureAvailableCustomDimensions02: platform is not supported");
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableCustomDimensions03(const AZStd::vector<string>& customDimensions)
    {
        CryLog("GameAnalytics::ConfigureAvailableCustomDimensions03: platform is not supported");
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableResourceCurrencies(const AZStd::vector<string>& resourceCurrencies)
    {
        CryLog("GameAnalytics::ConfigureAvailableResourceCurrencies: platform is not supported");
    }

    void GameAnalyticsSystemComponent::ConfigureAvailableResourceItemTypes(const AZStd::vector<string>& resourceItemTypes)
    {
        CryLog("GameAnalytics::ConfigureAvailableResourceItemTypes: platform is not supported");
    }

    void GameAnalyticsSystemComponent::ConfigureBuild(const string& build)
    {
        CryLog("GameAnalytics::ConfigureBuild: platform is not supported");
    }

    void GameAnalyticsSystemComponent::ConfigureUserId(const string& uId)
    {
        CryLog("GameAnalytics::ConfigureUserId: platform is not supported");
    }

    // initialize - starting SDK (need configuration before starting)
    void GameAnalyticsSystemComponent::Initialize(const string& gameKey, const string& gameSecret)
    {
        CryLog("GameAnalytics::Initialize: platform is not supported");
    }

    // add events
    void GameAnalyticsSystemComponent::AddBusinessEvent(const string& currency,
                                             int amount,
                                             const string& itemType,
                                             const string& itemId,
                                             const string& cartType)
    {
        CryLog("GameAnalytics::AddBusinessEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::AddResourceEvent(EGAResourceFlowType flowType,
                                             const string& currency,
                                             float amount,
                                             const string&itemType,
                                             const string& itemId)
    {
        CryLog("GameAnalytics::AddResourceEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::AddProgressionEvent(EGAProgressionStatus progressionStatus,
                                                         const string& progression01,
                                                         const string& progression02,
                                                         const string& progression03)
    {
        CryLog("GameAnalytics::AddProgressionEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::AddProgressionEventWithScore(EGAProgressionStatus progressionStatus,
                                                         const string& progression01,
                                                         const string& progression02,
                                                         const string& progression03,
                                                         int score)
    {
        CryLog("GameAnalytics::AddProgressionEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::AddDesignEvent(const string& eventId)
    {
        CryLog("GameAnalytics::AddDesignEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::AddDesignEventWithValue(const string& eventId, double value)
    {
        CryLog("GameAnalytics::AddDesignEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::AddErrorEvent(EGAErrorSeverity severity, const string& message)
    {
        CryLog("GameAnalytics::AddErrorEvent: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetEnabledInfoLog(bool flag)
    {
        CryLog("GameAnalytics::SetEnabledInfoLog: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetEnabledVerboseLog(bool flag)
    {
        CryLog("GameAnalytics::SetEnabledVerboseLog: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetEnabledManualSessionHandling(bool flag)
    {
        CryLog("GameAnalytics::SetEnabledManualSessionHandling: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetCustomDimension01(const string& dimension01)
    {
        CryLog("GameAnalytics::SetCustomDimension01: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetCustomDimension02(const string& dimension02)
    {
        CryLog("GameAnalytics::SetCustomDimension02: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetCustomDimension03(const string& dimension03)
    {
        CryLog("GameAnalytics::SetCustomDimension03: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetFacebookId(const string& facebookId)
    {
        CryLog("GameAnalytics::SetFacebookId: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetGender(EGAGender gender)
    {
        CryLog("GameAnalytics::SetGender: platform is not supported");
    }

    void GameAnalyticsSystemComponent::SetBirthYear(int birthYear)
    {
        CryLog("GameAnalytics::SetBirthYear: platform is not supported");
    }

    void GameAnalyticsSystemComponent::StartSession()
    {
        CryLog("GameAnalytics::StartSession: platform is not supported");
    }

    void GameAnalyticsSystemComponent::EndSession()
    {
        CryLog("GameAnalytics::EndSession: platform is not supported");
    }

    string GameAnalyticsSystemComponent::GetCommandCenterValueAsString(const string& key)
    {
        CryLog("GameAnalytics::getCommandCenterValueAsString: platform is not supported");
    }

    string GameAnalyticsSystemComponent::GetCommandCenterValueAsStringWithDefaultValue(const string& key, const string& defaultValue)
    {
        CryLog("GameAnalytics::GetCommandCenterValueAsStringWithDefaultValue: platform is not supported");
    }

    bool GameAnalyticsSystemComponent::IsCommandCenterReady()
    {
        CryLog("GameAnalytics::isCommandCenterReady: platform is not supported");
    }

    string GameAnalyticsSystemComponent::GetConfigurationsContentAsString()
    {
        CryLog("GameAnalytics::getConfigurationsContentAsString: platform is not supported");
    }

#endif // USE_GAMEANALYTICS
}
