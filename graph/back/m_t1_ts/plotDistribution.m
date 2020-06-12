%% Minutes
x_label =[0.5	1	2	4	8]



%% for DeadlinMissRatio

%Miss ratio
y_11 = [0.66802	0.66654	0.6646	0.66404	0.66458]
y_12 = [0.94966	0.95062	0.95264	0.95424	0.95752]
y_13 = [0.66334	0.66954	0.673	0.67712	0.67926]
y_14 = [0.56692	0.56942	0.58004	0.5819	0.58336]

%E[V_O]
%y_11 = [22.320205	22.320205	22.320205	22.320205	22.320205]
%y_12 = [11.675366	11.675366	11.675366	11.675366	11.675366]
%y_13 = [22.320205	22.320205	22.320205	22.320205	22.320205]
%y_14 = [24.189022	24.439078	24.439078	24.439078	24.439078]

%E[V_D]
%y_11 = [59.795073	59.894273	60.099509	60.234807	59.981779]
%y_12 = [29.729493	29.212248	29.158644	28.76319	28.578961]
%y_13 = [59.816723	59.17924	59.052512	59.02246	58.901971]
%y_14 = [66.962827	66.568339	65.885139	65.816606	65.933702]

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
legend({'E[t_s]=90s(Constant Bandwidth)','E[t_s]=30s(Multiple Bandwidth)','E[t_s]=90s(Multiple Bandwidth)','E[t_s]=120s(Multiple Bandwidth)'},'NumColumns',1);

hold off;
grid on;