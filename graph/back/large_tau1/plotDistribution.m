%% File size
%N=10000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	20	21	22	23	24	26]
%N=50000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	26	27	29]
%N=100000
%x_label =[0.5	1	1.5	2	2.5	3	3.5	4	4.5	5	5.5	6	6.5	7	7.5	8	8.5	9	9.5	10]

x_label =[0.000244141	0.000488281	0.000976563	0.001953125	0.00390625	0.0078125	0.015625	0.03125	0.0625	0.125	0.25	0.5	1]


%% for DeadlinMissRatio

%Miss ratio
y_11 = [0.2362	0.2295	0.2378	0.2372	0.2302	0.2377	0.2454	0.2334	0.2365	0.2334]
y_12 = [0.2464	0.25	0.2592	0.2559	0.2571	0.2667	0.2878	0.292	0.31	0.3132]


%E[V_O]
%y_11 = [441.87233	434.479949	439.811602	435.371951	444.822619	440.659312	441.897164	434.139521	441.221891	443.100421	447.72272	435.138412	436.84296]
%y_12 = [157.050427	159.404532	164.277928	174.538933	195.375122	224.452828	259.762218	290.141962	307.894766	323.488167	333.417475	334.480319	337.539205]


%E[V_D]
%y_11 = [776.965557	767.738511	775.142027	774.803055	777.489552	779.13532	783.343035	770.732786	778.625884	780.815415	784.089563	772.172094	776.49138]
%y_12 = [712.46987	711.816574	713.208963	716.266929	728.585354	736.653838	750.739519	764.743021	762.961376	767.610849	774.849716	773.152047	775.126355]





i = i+1;
figure(i)

semilogx(x_label,y_11,'-x', 'MarkerSize',10, 'LineWidth',1.3)
hold on
semilogx(x_label,y_12,'-s', 'MarkerSize',10, 'LineWidth',1.3)
hold on
%plot(x_label,y_21,'-+', 'MarkerSize',10, 'LineWidth',1.3)
%hold on
%plot(x_label,y_22,'-^', 'MarkerSize',10, 'LineWidth',1.3)
%hold on
%plot(x_label,y_31,'-d', 'MarkerSize',10, 'LineWidth',1.3)
%hold on
%plot(x_label,y_32,'-o', 'MarkerSize',10, 'LineWidth',1.3)
%hold on

ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
%ylabel('E[V_D]: MB')
%xlabel('E[t_0]:')
xlabel('\gamma_2')


%xticklabels({'62.5','125','250','500','1000','2000','4000','8000'});
%xticklabels({'10','20','40','80','160','320','640','1280'});
%xticklabels({'50','100','150','200','250','300','350','400'});
%xticklabels({'1',	'0.5',	'0.2',	'0.1',	'0.05',	'0.025',	'0.016666667',	'0.008333333',	'0.006666667',	'0.003333333',	'0.001666667'	,'0.000833333',	'0.000416667'});
xticklabels({'0.00025',	'0.0005',	'0.001',	'0.002',	'0.004',	'0.008',	'0.016',	'0.031',	'0.063',	'0.125',	'0.25',	'0.5',	'1'});




												
xlim([0.000244141, 1]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'Smooth connection','Unstable Connection'},'NumColumns',1);

hold off;
grid on;