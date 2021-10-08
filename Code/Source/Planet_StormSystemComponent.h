
#pragma once

#include <AzCore/Component/Component.h>

#include <Planet_Storm/Planet_StormBus.h>

namespace Planet_Storm
{
    class Planet_StormSystemComponent
        : public AZ::Component
        , protected Planet_StormRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Planet_StormSystemComponent, "{6d1e1f5c-4dfc-4e90-8efd-62c5951ca555}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Planet_StormSystemComponent();
        ~Planet_StormSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Planet_StormRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
