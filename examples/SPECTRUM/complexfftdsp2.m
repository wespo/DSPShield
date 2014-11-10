function [dspRes MatRes] = complexfftdsp2(fftData)

fftDataMag = [];
fftData(2) = 0;
for i = 1:2:512
    fftDataMag = [fftDataMag; abs(fftData(i) + (i*fftData(i+1)))];
end
%hold on;
figure(1);
%subplot(3,1,1);
fftDataMag = fftDataMag+1;
dspRes = [fftDataMag.' 0 fliplr(fftDataMag.')]/max(fftDataMag);
fniq = 44.1/2;
halfScale = 0:fniq/256:fniq-fniq/256;
scale = [-1*fliplr(halfScale) 0 halfScale];

plot(scale,dspRes, 'red');
title('Real DSP result, 12kHz AWG input 48kHz sample rate');


end

