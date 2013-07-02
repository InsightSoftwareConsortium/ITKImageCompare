/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkImageFileWriter.h"
#include "itkRandomImageSource.h"

int main( int argc, char * argv[] )
{
  if( argc < 3 )
    {
    std::cerr << "Usage: "
              << " randomImage1"
              << " randomImage2"
              << std::endl;
    }
  const char * randomImage1 = argv[1];
  const char * randomImage2 = argv[2];

  const unsigned int Dimension = 3;
  typedef unsigned short PixelType;

  typedef itk::Image< PixelType, Dimension > ImageType;

  typedef itk::RandomImageSource< ImageType > RandomSourceType;
  RandomSourceType::Pointer randomSource = RandomSourceType::New();
  RandomSourceType::SizeType size;
  size.Fill( 13 );
  randomSource->SetSize( size );
  randomSource->SetSpacing( 0.8 );
  randomSource->SetOrigin( 24.9 );

  typedef itk::ImageFileWriter< ImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetInput( randomSource->GetOutput() );

  writer->SetFileName( randomImage1 );
  try
    {
    writer->Update();

    // Get a different image.
    randomSource->SetMax( 777 );
    writer->SetFileName( randomImage2 );
    writer->Update();
    }
  catch( itk::ExceptionObject & error )
    {
    std::cerr << "Error: " << error << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
