/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
/// @version 2.0.0
///
/// @section License
/// Copyright 2020 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// @section Description
/// Center of Mass centroids clusters
///

#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/ImageProcessing/Centroid.hpp"
#include "NumCpp/ImageProcessing/Cluster.hpp"

#include <utility>
#include <vector>

namespace nc
{
    namespace imageProcessing
    {
        //============================================================================
        // Method Description:
        ///						Center of Mass centroids clusters
        ///
        /// @param				inClusters
        /// @return
        ///				std::vector<Centroid>
        ///
        template<typename dtype, class Alloc>
        std::vector<Centroid<dtype, Alloc>, Alloc> 
            centroidClusters(const std::vector<Cluster<dtype, Alloc>, Alloc>& inClusters) noexcept
        {
            STATIC_ASSERT_ARITHMETIC(dtype);

            std::vector<Centroid<dtype, Alloc>, Alloc> centroids;

            for (auto& cluster : inClusters)
            {
                centroids.emplace_back(cluster);
            }

            return centroids;
        }
    }
}
