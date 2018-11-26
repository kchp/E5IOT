%%  E5IOT Project
%%  Description
%   
%   Testing the accuracy of the systems ability to find the pitch perfect
%   frequencies. The script will create 6 test signals each containing the
%   carrier frequency and the pitch perfect frequency of a string. Then
%   use the same calculation script that will be running on ThingSpeak to
%   find the freqency of the test signal. Then print to the console  the
%   found frequency, the correct frequency and the error between them in
%   frequency and percentage.
%   
%% Setup
close all; clear; clc;

% Test signal
Fs = 12.5e3;
Ts = 1/Fs;
A = 3.5e-3;       % 7 mVpp signal amplitude
fcarr = 50;       % 50 Hz carrier frequency
f1 = 329.63;      % 329.63 Hz 1st string frequency    
f2 = 246.94;      % 246.94 Hz 2nd string frequency
f3 = 196;         % 196 Hz 3rd string frequency
f4 = 146.83;      % 146.83 Hz 4th string frequency
f5 = 110;         % 110 Hz 5th string frequency
f6 = 82.41;       % 82.41 Hz 6th string frequency
T = 0.1;          % Duration of 0.25 seconds
t = 0:Ts:T;

% Test signals containing pitch perfect frequency of all 6 strings and
% carrier frequency
x1 = A*sin(2*pi*fcarr*t) + A*sin(2*pi*f1*t);
x2 = A*sin(2*pi*fcarr*t) + A*sin(2*pi*f2*t);
x3 = A*sin(2*pi*fcarr*t) + A*sin(2*pi*f3*t);
x4 = A*sin(2*pi*fcarr*t) + A*sin(2*pi*f4*t);
x5 = A*sin(2*pi*fcarr*t) + A*sin(2*pi*f5*t);
x6 = A*sin(2*pi*fcarr*t) + A*sin(2*pi*f6*t);

%% Signal analysis 1st string
F1 = FindFreq(x1,Fs);
fprintf('1st string:\n');
fprintf('Frequency found %3.2f Hz\n',F1);
fprintf('Correct frequency %3.2f Hz\n',f1);
fprintf('Error; %3.2f Hz, %3.2f%%\n',F1-f1,100*(F1-f1)./f1);
fprintf('\n');

%% Signal analysis 2nd string
F2 = FindFreq(x2,Fs);
fprintf('2nd string:\n');
fprintf('Frequency found %3.2f Hz\n',F2);
fprintf('Correct frequency %3.2f Hz\n',f2);
fprintf('Error; %3.2f Hz, %3.2f%%\n',F2-f2,100*(F2-f2)./f2);
fprintf('\n');

%% Signal analysis 3rd string
F3 = FindFreq(x3,Fs);
fprintf('3rd string:\n');
fprintf('Frequency found %3.2f Hz\n',F3);
fprintf('Correct frequency %3.2f Hz\n',f3);
fprintf('Error; %3.2f Hz, %3.2f%%\n',F3-f3,100*(F3-f3)./f3);
fprintf('\n');

%% Signal analysis 4th string
F4 = FindFreq(x4,Fs);
fprintf('4th string:\n');
fprintf('Frequency found %3.2f Hz\n',F4);
fprintf('Correct frequency %3.2f Hz\n',f4);
fprintf('Error; %3.2f Hz, %3.2f%%\n',F4-f4,100*(F4-f4)./f4);
fprintf('\n');

%% Signal analysis 5th string
F5 = FindFreq(x5,Fs);
fprintf('5th string:\n');
fprintf('Frequency found %3.2f Hz\n',F5);
fprintf('Correct frequency %3.2f Hz\n',f5);
fprintf('Error; %3.2f Hz, %3.2f%%\n',F5-f5,100*(F5-f5)./f5);
fprintf('\n');

%% Signal analysis 6th string
F6 = FindFreq(x6,Fs);
fprintf('6th string:\n');
fprintf('Frequency found %3.2f Hz\n',F6);
fprintf('Correct frequency %3.2f Hz\n',f6);
fprintf('Error; %3.2f Hz, %3.2f%%\n',F6-f6,100*(F6-f6)./f6);
fprintf('\n');

%% Used for documentation of precision

fprintf('Precision of analysis code, using pitch-perfect signals\n');
fprintf('1st string (high E): ');
fprintf('Correct frequency %3.2f Hz; Frequency found %3.2f Hz; Error; %3.2f Hz, %3.2f%%\n',f1,F1,F1-f1,100*(F1-f1)./f1);
fprintf('2nd string (B):      ');
fprintf('Correct frequency %3.2f Hz; Frequency found %3.2f Hz; Error; %3.2f Hz, %3.2f%%\n',f2,F2,F2-f2,100*(F2-f2)./f2);
fprintf('3rd string (G):      ');
fprintf('Correct frequency %3.2f Hz; Frequency found %3.2f Hz; Error; %3.2f Hz, %3.2f%%\n',f3,F3,F3-f3,100*(F3-f3)./f3);
fprintf('4th string (D):      ');
fprintf('Correct frequency %3.2f Hz; Frequency found %3.2f Hz; Error; %3.2f Hz, %3.2f%%\n',f4,F4,F4-f4,100*(F4-f4)./f4);
fprintf('5th string (A):      ');
fprintf('Correct frequency %3.2f Hz; Frequency found %3.2f Hz; Error; %3.2f Hz, %3.2f%%\n',f5,F5,F5-f5,100*(F5-f5)./f5);
fprintf('6th string (low E):  ');
fprintf('Correct frequency %3.2f Hz; Frequency found %3.2f Hz;  Error; %3.2f Hz, %3.2f%%\n',f6,F6,F6-f6,100*(F6-f6)./f6);
