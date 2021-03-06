function kfact = k_factor(imp_resp_fq)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   K-Factor estimator function:                (Raul de Lacerda, 06/04/2007)
%      kfact = k_factor(imp_resp_fq)
%
%      k_factor is a function created to estimate the K-Factor of the files
%      generated by the EMOS TestBed.
%      - imp_resp_fq is the input file with the Impulse Responses dim(t,fq,Tx,Rx)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
[N_t,N_fq,N_Tx,N_Rx]   = size(imp_resp_fq);
%%% N_t   = Number of samples
%%% N_fq = Impulse response length
%%% N_Tx  = Number of TX antennas
%%% N_Rx  = Number of RX antennas
% carriers    = [1:20 45:63];

N_fq_real   = N_fq;
channel     = abs(imp_resp_fq);
tmp         = zeros(1,N_fq_real,1,1);
% Expectation of the channel impulse response (M)
for aa = 1:N_t,
    for bb = 1:N_Tx,
        for cc = 1: N_Rx,
            channel(aa,:,bb,cc) = channel(aa,:,bb,cc)/norm(channel(aa,:,bb,cc));
            tmp = tmp + channel(aa,:,bb,cc);
        end
    end
end
M = tmp/(N_t*N_Tx*N_Rx);
% Expectation of the channel impulse response (M) - the real channel
% impulse responses (H = mean(h-M)^2)
tmp         = zeros(1,N_fq_real,1,1);
for aa = 1:N_t,
    for bb = 1:N_Tx,
        for cc = 1: N_Rx,
            tmp = tmp + (channel(aa,:,bb,cc)-M).^2;
        end
    end
end
H = tmp/(N_t*N_Tx*N_Rx);
kfact = mean(M.^2./H);
