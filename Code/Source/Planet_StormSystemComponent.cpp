
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Planet_StormSystemComponent.h"

namespace Planet_Storm
{
    void Planet_StormSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Planet_StormSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Planet_StormSystemComponent>("Planet_Storm", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Planet_StormSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Planet_StormService"));
    }

    void Planet_StormSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Planet_StormService"));
    }

    void Planet_StormSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Planet_StormSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    Planet_StormSystemComponent::Planet_StormSystemComponent()
    {
        if (Planet_StormInterface::Get() == nullptr)
        {
            Planet_StormInterface::Register(this);
        }
    }

    Planet_StormSystemComponent::~Planet_StormSystemComponent()
    {
        if (Planet_StormInterface::Get() == this)
        {
            Planet_StormInterface::Unregister(this);
        }
    }

    void Planet_StormSystemComponent::Init()
    {
    }

    void Planet_StormSystemComponent::Activate()
    {
        Planet_StormRequestBus::Handler::BusConnect();
    }

    void Planet_StormSystemComponent::Deactivate()
    {
        Planet_StormRequestBus::Handler::BusDisconnect();
    }
}
