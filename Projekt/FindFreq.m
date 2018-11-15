function [freq] = FindFreq(x)
% Function used to find the frequency of the string

% All frequencies are in Hz
Fs = 1024;  % Extract sample frequency from signal


% Analyse signal
x = highpass(x,60,Fs);
Xdft = fft(x);
[~,I] = max(abs(Xdft));
fIndex = 0:Fs/length(x):Fs/2;

% Return value
freq = fIndex(I);