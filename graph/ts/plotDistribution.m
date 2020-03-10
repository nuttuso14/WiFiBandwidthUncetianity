%% File size
%N=10000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	20	21	22	23	24	26]
%N=50000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	26	27	29]
%N=100000
%x_label =[0.5	1	1.5	2	2.5	3	3.5	4	4.5	5	5.5	6	6.5	7	7.5	8	8.5	9	9.5	10]

x_label =[0.000555556	0.000617284	0.000694444	0.000793651	0.000925926	0.001111111	0.001388889	0.001851852	0.002777778	0.005555556	0.016666667]


%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.051395	0.0573	0.0625	0.0721	0.0831	0.1007	0.1239	0.163	0.2359	0.4057	0.7682]
%y_12 = [0.061594	0.0699	0.0769	0.0858	0.0997	0.1172	0.1407	0.1805	0.2622	0.4501	0.8227]


%E[V_O]
%y_11 = [58.990218	58.661322	58.499141	57.922252	57.3623	57.099702	56.274034	54.967513	52.131965	44.266455	26.491771]
%y_12 = [34.360821	34.269571	34.22304	34.09205	33.914688	33.752447	33.402178	32.68401	31.449009	27.852577	17.550694]

%E[V_D]
y_11 = [97.241053	96.929608	96.569461	96.036349	95.447918	94.61393	93.378582	91.344616	87.429779	77.194715	51.741466]
y_12 = [96.741513	96.343208	95.917178	95.484524	94.621144	93.618874	92.383393	90.282934	85.862416	74.924854	47.045946]


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

%ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
ylabel('E[V_D]: MB')
%xlabel('E[t_0]:')
xlabel('\mu')


%xticklabels({'62.5','125','250','500','1000','2000','4000','8000'});
%xticklabels({'10','20','40','80','160','320','640','1280'});
%xticklabels({'50','100','150','200','250','300','350','400'});
%xticklabels({'1',	'0.5',	'0.2',	'0.1',	'0.05',	'0.025',	'0.016666667',	'0.008333333',	'0.006666667',	'0.003333333',	'0.001666667'	,'0.000833333',	'0.000416667'});
xticklabels({'0.0005',	'0.0006',	'0.0007',	'0.0008',	'0.0009',	'0.0011',	'0.0014',	'0.0019',	'0.0028',	'0.0056',	'0.017'});


												
xlim([0.000555556, 0.016666667]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'Smooth connection','Unstable Connection'},'NumColumns',1);

hold off;
grid on;