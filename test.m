clear,clc
f=imread('E:\test\136618543024.png');
g=imread('E:\test\1366185349620.png');
k=imread('E:\test\ke.jpg');
size(f);
whos f;
imshow(k);
imwrite(f,'patient','tif')
imwrite(g,'filename.jpg','quality',10)
k=imfinfo ('E:\matlab\filename.jpg');
image_bytes=k.Width*k.Height*k.BitDepth/8;
compressed_bytes=k.FileSize;
compression_ratio=image_bytes/compressed_bytes;
imfinfo E:\test\ke.jpg
fp=f(end:-1:1,:);
imshow(fp)
plot(f(384,:));
fc=f(257:768,257:768);
imshow(fc)
fs=f(1:2:end,1:2:end);
imshow(fs)
g1=imadjust(g,[0.5,0.75],[0,1]);
imshow(g1),figure
g2=imcomplement(f);
imshow(g2),figure
g3=imadjust(f,[],[],2);
imshow(g3)