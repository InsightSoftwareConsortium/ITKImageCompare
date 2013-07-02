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
