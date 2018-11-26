function [freq] = FindFreq(x,fs)
% Function used to find the frequency of the string
% All frequencies are in Hz
% -------------------------------------------------------
% x: signal to be analysed
% fs: sampling frequency used
% -------------------------------------------------------

x = [x zeros(1,2^12-length(x))]; % zeropad signal for better frequency resolution
N = length(x);  % Number of samples in signal
fIndex = 0:fs/N:fs/2; % Frequency resolution

% Filter signal to suppress carrier frequency
x = highpass(x,60,fs);

% Analyse signal
Xdft = fft(x,N);
[~,I] = max(abs(Xdft)); % Find index containing max peak value

% Return frequency of found index
freq = fIndex(I);