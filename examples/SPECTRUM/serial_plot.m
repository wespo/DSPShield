%fft spectrum printer
%setup serial.
if(size(instrfind) ~= [0 0])
    fclose(instrfind);
end
s = serial('COM23','BaudRate', 115200); %/dev/tty.usbmodemfd121
s.InputBufferSize = 2^16;
fopen(s);
%serial print
%pause(5);
data = fscanf(s) %boot message
pause(5);
while(1)%s.bytesAvailable > 0)
    %'here'
    data = fscanf(s);
    data = strsplit(data,',');
    tempData = data;
    if(cell2mat(data(1)) == '$') %check for flag at start
        data = data(2:end-1); %slice off junk CR
        len = length(data);
        intData = zeros(1, len);
        for index = 1:len
            intData(index) = str2num(data{index});
        end
        if(length(intData) == 512)
            complexfftdsp2(intData);
        end
        %intData
        pause(0.01);
        

    end
        
end

fclose(s);

% protocol for sending output to matlab
%'$'<length><array ints><cr><lf>(each element is comma separated)