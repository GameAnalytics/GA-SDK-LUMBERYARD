
#include "StdAfx.h"
#include <platform_impl.h>

#include <AzCore/Memory/SystemAllocator.h>

#include "GameAnalyticsSystemComponent.h"
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
#include "GameAnalytics.h"
#endif

#include <IGem.h>

namespace GameAnalytics
{
    class GameAnalyticsModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(GameAnalyticsModule, "{F528B309-CFB4-4B91-AD76-FEFBC2384BEB}", CryHooksModule);
        AZ_CLASS_ALLOCATOR(GameAnalyticsModule, AZ::SystemAllocator, 0);

        GameAnalyticsModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                GameAnalyticsSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<GameAnalyticsSystemComponent>(),
            };
        }
    private:
        void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
        {
            switch(event)
            {
                case ESYSTEM_EVENT_FAST_SHUTDOWN:
                case ESYSTEM_EVENT_FULL_SHUTDOWN:
#if defined(DARWIN) || defined(WIN32) || defined(LINUX)
                    gameanalytics::GameAnalytics::onQuit();
#endif
                    break;
            }
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(GameAnalytics_6ef71eb103914b538c99463839ce4c51, GameAnalytics::GameAnalyticsModule)
