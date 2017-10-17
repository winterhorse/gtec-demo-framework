#ifndef FSLUTIL_VULKAN1_0_UTIL_PHYSICALDEVICEUTIL_HPP
#define FSLUTIL_VULKAN1_0_UTIL_PHYSICALDEVICEUTIL_HPP
/****************************************************************************************************************************************************
* Copyright 2017 NXP
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
*    * Neither the name of the NXP. nor the names of
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

#include <FslBase/BasicTypes.hpp>
#include <vector>
#include <vulkan/vulkan.h>

namespace Fsl
{
  namespace Vulkan
  {
    namespace PhysicalDeviceUtil
    {

      //! vkGetPhysicalDeviceFormatProperties
      inline VkFormatProperties GetPhysicalDeviceFormatProperties(const VkPhysicalDevice physicalDevice, const VkFormat format)
      {
        VkFormatProperties properties;
        vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &properties);
        return properties;
      }


      //! vkGetPhysicalDeviceImageFormatProperties
      inline bool TryGetPhysicalDeviceImageFormatProperties(const VkPhysicalDevice physicalDevice, const VkFormat format, const VkImageType type,
                                                            const VkImageTiling tiling, const VkImageUsageFlags usage, const VkImageCreateFlags flags,
                                                            VkImageFormatProperties& rImageFormatProperties)
      {
        return (vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, &rImageFormatProperties) == VK_SUCCESS);
      }


      //! @brief Get the physical devices queue family properties
      //! vkGetPhysicalDeviceQueueFamilyProperties
      std::vector<VkQueueFamilyProperties> GetPhysicalDeviceQueueFamilyProperties(const VkPhysicalDevice device);


      //! @brief Check if image tiling is available
      bool IsImageTilingAvailable(const VkPhysicalDevice physicalDevice, const VkImageTiling imageTiling, const VkFormat format, const VkImageType type,
                                  const VkImageCreateFlags flags, const VkExtent3D& extent, const uint32_t mipLevels,
                                  const uint32_t arrayLayers, const VkSampleCountFlags sampleCounts, const VkDeviceSize resourceSize);
    }
  }
}

#endif