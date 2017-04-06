/****************************************************************************************************************************************************
* Copyright (c) 2014 Freescale Semiconductor, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    * Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*
*    * Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*
*    * Neither the name of the Freescale Semiconductor, Inc. nor the names of
*      its contributors may be used to endorse or promote products derived from
*      this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************************************************************************************/

#include <FslDemoAppG2D/Setup/RegisterDemoAppG2D.hpp>
#include <FslDemoApp/Setup/HostDemoAppSetup.hpp>
#include <FslDemoApp/Setup/IDemoAppRegistry.hpp>
#include <FslDemoApp/Host/DemoAppSetup.hpp>
#include <FslDemoApp/Host/DemoHostFeatureUtil.hpp>
#include <FslDemoHost/Service/ServicePriorityList.hpp>
#include <FslDemoHost/Service/ServiceRegistry.hpp>
#include <FslDemoHost/Service/ThreadLocal/ThreadLocalSingletonServiceFactoryTemplate.hpp>
#include <FslDemoPlatform/Setup/IDemoHostRegistry.hpp>
#include <FslDemoHostStub/StubDemoHostSetup.hpp>
#include <FslNativeGraphicsG2D/NativeGraphicsService.hpp>

namespace Fsl
{
  namespace
  {
    const DemoHostFeature CommenSetup(const HostDemoAppSetup& setup)
    {
      // Use the EGLDemoHost for OpenGLES
      std::deque<DemoHostFeatureName::Enum> eglHostFeatures;
      eglHostFeatures.push_back(DemoHostFeatureName::G2D);
      setup.TheHostRegistry.Register(eglHostFeatures, StubDemoHostSetup::Get());
      setup.TheServiceRegistry.Register<ThreadLocalSingletonServiceFactoryTemplate<G2D::NativeGraphicsService, INativeGraphicsService> >(ServicePriorityList::NativeGraphicsService());

      return DemoHostFeature(DemoHostFeatureName::G2D, DemoHostFeatureUtil::EncodeG2DVersion(1));
    }
  }


  void RegisterDemoAppG2D::Register(const HostDemoAppSetup& setup, const std::shared_ptr<IDemoAppFactory>& appFactory)
  {
    const DemoHostFeature feature = CommenSetup(setup);
    const DemoAppSetup demoAppSetup(appFactory);
    setup.TheDemoAppRegistry.Register(demoAppSetup, feature);
  }


  void RegisterDemoAppG2D::Register(const HostDemoAppSetup& setup, const std::shared_ptr<IDemoAppFactory>& appFactory, const std::shared_ptr<Fsl::ADemoOptionParser> appOptionParser)
  {
    const DemoHostFeature feature = CommenSetup(setup);
    const DemoAppSetup demoAppSetup(appFactory, appOptionParser);
    setup.TheDemoAppRegistry.Register(demoAppSetup, feature);
  }
}