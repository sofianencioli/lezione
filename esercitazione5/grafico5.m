% Dati Benchmark Algoritmi di Ordinamento
dimensione = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

% Tempi di esecuzione (in secondi)
bubble    = [2.4354e-07, 2.7346e-07, 7.3052e-07, 1.35545e-06, 4.4438e-06, 4.44582e-05, 8.18539e-05, 0.000292351, 0.000973756, 0.00418286, 0.0300204, 0.138026, 0.554474];
insertion = [2.2585e-07, 2.8623e-07, 5.9859e-07, 7.1166e-07, 2.42087e-06, 2.0041e-05, 2.39359e-05, 9.41521e-05, 0.000458677, 0.00204561, 0.0150887, 0.0620029, 0.201641];
selection = [2.234e-07, 3.0799e-07, 7.0044e-07, 9.4511e-07, 2.94941e-06, 1.03099e-05, 3.02513e-05, 0.000107635, 0.000542363, 0.00271637, 0.0166867, 0.0541672, 0.188918];
quick     = [5.9463e-07, 1.0843e-06, 2.28582e-06, 2.48231e-06, 5.56539e-06, 1.43738e-05, 2.39617e-05, 5.64283e-05, 0.000161116, 0.000461414, 0.00179518, 0.00424873, 0.0295992];
merge     = [1.02882e-06, 2.29173e-06, 5.49444e-06, 7.24897e-06, 1.37146e-05, 2.84716e-05, 5.99949e-05, 0.000140485, 0.000365922, 0.0013894, 0.00365331, 0.00863514, 0.0499306];
std_sort  = [3.54974e-05, 4.23294e-05, 4.16966e-05, 2.96824e-05, 2.62557e-05, 2.26888e-05, 2.38807e-05, 2.51118e-05, 3.02164e-05, 4.42834e-05, 5.65262e-05, 4.99809e-05, 6.68001e-05];

%% Plot 1: Scala Lineare
figure(1);
plot(dimensione, bubble,  'LineWidth', 1.5); hold on;
plot(dimensione, insertion, 'LineWidth', 1.5);
plot(dimensione, selection, 'LineWidth', 1.5);
plot(dimensione, quick, 'LineWidth', 1.5);
plot(dimensione, merge, 'LineWidth', 1.5);
plot(dimensione, std_sort, 'LineWidth', 1.5);
grid on;
title('Confronto Algoritmi di Ordinamento');
xlabel('Dimensione Vettore (N)');
ylabel('Tempo (secondi)');
legend('Bubble', 'Insertion', 'Selection', 'Quick', 'Merge', 'std::sort', 'Location', 'northwest');