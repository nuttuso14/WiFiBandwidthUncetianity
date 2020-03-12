%% Minutes
x_label =[0.5	1	2	4	8]



%% for DeadlinMissRatio

%Miss ratio
y_11 = [0.56804	0.57198	0.56782	0.5698	0.57382]
y_12 = [0.63396	0.63948	0.6392	0.64674	0.64932]
y_13 = [0.56368	0.57112	0.58176	0.58518	0.5873]
y_14 = [0.48364	0.491	0.5034	0.50548	0.5093]

%E[V_O]
%y_11 = [22.290307	22.332287	22.345873	22.208345	22.286482]
%y_12 = [13.232074	12.611311	12.458878	12.002413	11.65042]
%y_13 = [22.145324	21.426445	20.773726	20.321512	20.008151]
%y_14 = [33.265131	31.932602	31.050084	30.297557	30.125096]

%E[V_D]
%y_11 = [66.898115	66.755818	67.032943	66.900124	66.522183]
%y_12 = [62.569633	62.201129	62.158067	61.492309	61.602936]
%y_13 = [66.972434	66.44656	65.724884	65.474251	65.54487]
%y_14 = [71.474543	71.051157	70.196245	70.143041	69.980344]

i = i+1;
figure(i)

semilogx(x_label,y_11,'-d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_12,'--s', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_13,'--d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_14,'--o', 'MarkerSize',8, 'LineWidth',1.1)
hold on


ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
%ylabel('E[V_D]: MB')
xlabel('E[t_2] (Unit: E[t_1])')


xticklabels({'0.5',	'1',	'2',	'4',	'8'});

												
xlim([0.5, 8]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'b_2=b_1(Constant Bandwidth)','b_2=0.5b_1(Multiple Bandwidth)','b_2=b_1(Multiple Bandwidth)','b_2=2b_1(Multiple Bandwidth)'},'NumColumns',1);

hold off;
grid on;