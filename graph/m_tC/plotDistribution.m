%% Minutes
x_label =[1 2 3 4 5 6 7 8 9 10]



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.47408	0.44594	0.42782	0.42008	0.41148	0.40544	0.40196	0.39248	0.39162	0.38634]
%y_12 = [0.48556	0.45086	0.43552	0.42368	0.4164	0.40884	0.4063	0.39902	0.39902	0.39468]
%y_13 = [0.48376	0.45292	0.43654	0.42484	0.41798	0.41012	0.4038	0.39848	0.39684	0.39572]
%y_14 = [0.48616	0.45186	0.43808	0.42212	0.41522	0.4112	0.408	0.40342	0.4041	0.3957]

%E[V_O]
%y_11 = [40.712821	54.109515	61.081292	65.699485	68.99064	71.670627	73.882403	75.848724	77.494195	78.981168]
%y_12 = [38.038188	51.57039	58.769768	63.848651	67.00775	69.742128	71.889418	74.115621	75.628548	77.108442]
%y_13 = [37.033599	50.180428	57.839074	62.376278	66.182143	68.857994	71.270866	73.384955	74.796806	75.990011]
%y_14 = [35.997183	49.910164	56.792074	61.645643	65.546063	68.326991	70.395707	72.36688	73.886634	75.489181]

%E[V_D]
y_11 = [184.09298	187.853388	189.858453	190.880963	192.165485	193.103683	193.809623	195.073866	195.20564	195.860078]
y_12 = [182.208768	186.662724	188.573468	190.257562	191.355377	192.345603	193.112804	194.161902	194.440083	195.009804]
y_13 = [182.494546	186.266715	188.331157	189.753987	191.392075	192.260783	193.117012	193.947956	194.172744	194.346561]
y_14 = [182.27412	186.117465	187.74124	190.025955	190.994357	191.747147	192.146515	192.858739	193.068734	194.149267]


i = i+1;
figure(i)

plot(x_label,y_11,'-d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
plot(x_label,y_12,'--s', 'MarkerSize',8, 'LineWidth',1.1)
hold on
plot(x_label,y_13,'--d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
plot(x_label,y_14,'--o', 'MarkerSize',8, 'LineWidth',1.1)
hold on


%ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
ylabel('E[V_D]: MB')
xlabel('E[T_C] (Unit: minutes)')


xticklabels({'1','2','3','4','5','6','7','8','9','10'});

												
xlim([1, 10]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'r_2=r_1 (Constant Bandwidth)','r_2=2r_1(Multiple Bandwidth)','r_2=3r_1(Multiple Bandwidth)','r_2=4r_1(Multiple Bandwidth)'},'NumColumns',1);

hold off;
grid on;