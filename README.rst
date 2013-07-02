ImageCompare
============

Description
-----------

This tool is a simple command line application that reads two images and
compares their content. It has a built-in degree of tolerance, so the images
don't have to be identical pixel by pixel.

Usage
-----

Run the command line executable::

  ImageCompare testImage, baselineImage1, [baselineImage2, baselineImage3, ...]

Note that if you supply more than one baselineImage, this test will pass if any
of them match the *testImage*.  A executable return value of 0 indicates the
images are the same.  A non-zero return value indicates the images are
different.
