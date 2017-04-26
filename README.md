WIP:

A simple OpenCV based gray scale image converter.

To convert the image to a comma separated text file of gray values:

./gray2text.x <image.tif> [-o values.csv]

If the -o option is omitted then the output goes to stdout.

To convert it back to an image

./text2gray.x [<textFile.csv>] -o imagefile.tif

If the text file is omitted then the input is read from stdin.
